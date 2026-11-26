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

- Initially built with `cmake .` and `make`; the final build uses a direct
  Makefile to avoid a dependency on the judge's CMake version.
- Compared output with an independent Python list-removal reference for all
  3,240 pairs satisfying 1 <= m <= n <= 80.
- Checked n = 3000 with m = 1, 2, 3, 1499, 2999, and 3000.
- AddressSanitizer and UndefinedBehaviorSanitizer passed (1, 1), (5, 3),
  (3000, 1), and (3000, 3000), including leak checks.
- The sample-data directory mentioned in README.md was unavailable.

## Submission history

- 879538: Compile Error using HTTPS; no compiler diagnostics were returned.
- 879540: Compile Error using SSH on port 443; no diagnostics were returned.
- Replaced CMake with a direct GNUmakefile after these failures.
- 879545: Compile Error using HTTPS with the direct GNUmakefile.
- 879546: Compile Error using standard GitHub SSH with the same code.
- Renamed GNUmakefile to Makefile for the final compatibility attempt.
- 879547: Compile Error using HTTPS and the conventional Makefile.
- All five allowed submissions are exhausted, with a best reported score of
  0. The API supplied no compiler or clone diagnostics for any attempt;
  the remote failure remains unresolved despite successful local builds.
