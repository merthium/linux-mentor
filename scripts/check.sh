#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
for dir in chapters/*; do
  [[ -d "$dir" ]] || continue
  echo "Kontrol: $dir"
  timeout 30 bash "$dir/check.sh"
done
