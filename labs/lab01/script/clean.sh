#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
if [[ -f build/CMakeCache.txt ]]; then
    cmake --build build --target clean
fi
