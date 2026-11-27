#!/usr/bin/env bash
# Runs cppcheck on the Cylph codebase with the project's flags.
# Suppressions (false positives we accept) live in cppcheck-suppressions.txt.

set -euo pipefail

cppcheck \
    --enable=warning,style,performance,portability \
    --inline-suppr \
    --suppressions-list=cppcheck-suppressions.txt \
    --error-exitcode=1 \
    --std=c11 \
    --quiet \
    src/ include/