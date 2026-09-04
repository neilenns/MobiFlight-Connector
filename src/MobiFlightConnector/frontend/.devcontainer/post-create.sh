#!/usr/bin/env bash
set -e

# Update the .zshrc with project-specific settings.
# 1. Set the default user to node to get rid of the node@container segment
# 2. Overwrite the prompt_git() method in the segment, temporarily, to fix performance
# issues when running the devcontainer via a local clone.
cat >> "$HOME/.zshrc" <<'EOF'
DEFAULT_USER=node

prompt_git() {
}
EOF
