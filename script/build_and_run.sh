#!/usr/bin/env bash
set -euo pipefail
bash "$(dirname "$0")/build.sh"
bash "$(dirname "$0")/run.sh" "$@"
