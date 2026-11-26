# Solution and validation

Build nodes numbered 1 through n manually, with one next pointer per node,
and connect the tail to the head. Keep a pointer to the predecessor of the
node where counting starts. Advancing this pointer m - 1 times makes its
successor the m-th node. Print that successor, unlink it, and delete it.
The predecessor then points to the next counting start, preserving the
invariant. Print and delete the final node when it points to itself.

This uses O(nm) time and O(n) memory. No STL containers or external libraries
are used, and every allocated node is deleted exactly once.

## Local validation

- Built with the judge's `cmake .` and `make` workflow.
- Compared output with an independent Python list-removal reference for all
  3,240 pairs satisfying 1 <= m <= n <= 80.
- Checked n = 3000 with m = 1, 2, 3, 1499, 2999, and 3000.
- AddressSanitizer and UndefinedBehaviorSanitizer passed (1, 1), (5, 3),
  (3000, 1), and (3000, 3000), including leak checks.
- The sample-data directory mentioned in README.md was unavailable.
