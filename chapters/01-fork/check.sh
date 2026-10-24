set -eu
out=$(build/01-fork)
echo "$out"
grep -q 'child value=42' <<< "$out"
grep -q 'parent value=7 child_exit=0' <<< "$out"
