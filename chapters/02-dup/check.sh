set -eu
out=$(build/02-dup)
echo "$out"
grep -q 'original=ab duplicate=cd independent=ab' <<< "$out"
