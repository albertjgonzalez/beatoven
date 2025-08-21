# Beat Oven — Product Spec (Private/Internal)

This is the internal, concrete spec for Beat Oven. It refines our collaboration model and clarifies data, flows, and constraints for an MVP.

Visibility
- Private/Internal: Do not redistribute outside the team. This file exists here for engineering alignment. If the repository is public, this file will be visible to everyone.

## Product Summary

Beat Oven is a desktop app that helps music producers collaborate on DAW projects without a central file server. Each project has a single canonical Main copy and personal Local workspaces per collaborator. Anyone can pull the latest Main from an online collaborator; only the project owner can promote a Local snapshot to become the new Main. The app tracks project hashes to determine freshness and relies on a lightweight hosted service for auth, project metadata, and online presence—not for file storage.

## Core Concepts

- Project root: A folder on disk where DAW projects live. Beat Oven watches this root.
- Main: The canonical, shared version of a project. Exists on each collaborator's machine under `project/main/`.
- Local: A personal workspace for changes. Each user has `project/local/<username>/` snapshots.
- Pull-only model: Collaborators pull Main from each other; there is no push. Only the owner can promote a Local snapshot to Main.
- Hashing: Beat Oven computes a deterministic hash of folder contents (with ignore rules) to detect changes and compare versions.

## System Components

- Desktop app
  - Watches the projects root, maintains a local SQLite database, computes hashes, manages pulls/promotions, and launches DAW sessions.
- Hosted service (our infra)
  - Auth and profiles
  - Friends/collaborators graph
  - Project registry (project IDs, owner, collaborator list and roles)
  - Presence and advertised hashes (who's online and what Main hash they have)
  - No project file storage

## Desktop UX

- Main window: List of projects discovered under the projects root.
- Tabs:
  - Collaborators: Friends list, invitations, project membership.
  - Settings: Project root path, ignore patterns, DAW associations, bandwidth limits.
- Project detail sidebar:
  - Metadata: Name, path, size, created/updated timestamps
  - Versions: Your Main hash, your Local hash, status (Up to date / Behind / Diverged)
  - Collaborators: List with roles (Owner/Collaborator) and online status
  - Actions:
    - Pull latest Main (from selected online peer)
    - Open in DAW (from Main or your Local)
    - Owner only: Promote Local to Main, Manage collaborators, Revert Main to backup
    - View backups/version history (local archives of prior Main)

## Project Layout on Disk

```
project/
  .beatoven/                # metadata (project ID, ignore rules, local state)
  main/                     # local copy of canonical Main
  local/<username>/         # personal workspace snapshots
  backups/<timestamp>/      # archived versions of Main
```

- `.beatoven` also stores a `.beatovenignore` for hash computation (exclude DAW caches, temp files, OS clutter, etc.).

## Key Flows

1) Create a project
- User creates a DAW project under the projects root (or imports an existing folder).
- Beat Oven initializes `.beatoven`, sets `main/` from the current project state, creates `local/<me>/`, computes and stores hashes, registers the project with the hosted service, and invites collaborators.

2) Pull latest Main
- Beat Oven shows online collaborators and their advertised Main hash.
- If someone has a newer Main, user clicks Pull.
- App backs up current `main/` to `backups/<timestamp>/`, then fetches files from the selected peer to replace `main/`.
- Hashes are recomputed and stored.

3) Work locally
- From the project sidebar, user chooses Open Local, which launches the DAW using `local/<me>/` as the working directory (or a new timestamped snapshot within it).
- Saves remain isolated to Local; Main is untouched until a promotion.

4) Promote (owner only)
- Owner selects one of their Local snapshots and promotes it to Main.
- App verifies the owner's Main hasn't changed since the Local snapshot was created; if it has, owner must pull and reconcile manually.
- On success, current `main/` is archived to `backups/<timestamp>/`, and the selected Local snapshot becomes the new `main/`.
- New Main hash is computed and advertised via the hosted service.

## Sync and Hashing

- Local SQLite stores project metadata, collaborator roles, last-known hashes, and presence snapshots.
- A background watcher updates hashes when files change (respecting ignore rules).
- Accuracy of "who has the latest Main" depends on collaborators being online; hashes are authoritative only when peers are reachable.
- No merge logic; changes are serialized via promotions (the owner is the gate).

## Roles and Permissions

- Owner
  - Add/remove collaborators, assign roles
  - Promote Local to Main
  - Revert to previous Main (from backups)
  - Optional: Lock/unlock project
- Collaborator
  - Pull Main
  - Work in Local
  - Optional: Propose promotion (visible request to owner; no automatic change)

## Networking and Security (MVP)

- Discovery: Hosted service provides presence and latest advertised hashes for collaborators on a project.
- Transfer: Direct peer-to-peer file transfer initiated by the pulling user to a selected online peer.
- Auth: Tokens issued by the hosted service for peer verification.
- Encryption: TLS for peer data transfer.
- No server-side file storage; optional relays can be considered later.

## Constraints and Limitations (v1)

- All collaborators must be online to discover and pull the latest Main.
- No automatic conflict resolution or merges; owner's promotion is the single source of truth.
- Large projects depend on peer bandwidth; pulls may start as whole-folder transfers (incremental sync later).
- Cross-DAW quirks are out of scope; Beat Oven moves files, your DAW handles project internals.

## Settings (Recommended)

- Projects root folder
- Ignore patterns (`.beatovenignore`)
- DAW executable mapping per file type/project
- Bandwidth limits and transfer concurrency
- Backup retention policy (number of Main backups to keep)

## Non-Goals (MVP)

- Automatic merging or diffing of DAW project files
- Cloud file storage or CDN
- Offline reconciliation
- Complex role hierarchies beyond Owner/Collaborator

## Open Questions (to track)

- Incremental transfer protocol and dedup (chunking strategy, rolling hash vs. file mtime/size heuristic)
- NAT traversal options and fallback relays
- Cross-platform filesystem watching and path case sensitivity
- Handling very large media assets and partial pulls (e.g., stems only)