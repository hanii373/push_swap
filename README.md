*This project has been created as part of the 42 curriculum by gogalsty, [login2].*

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using only two stacks (`a` and `b`) and a limited set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), producing the smallest possible sequence of operations.

The program implements four distinct sorting strategies and selects between them automatically (adaptive mode) or on demand via flags.

---

## Instructions

### Compilation

```bash
make
```

This compiles `push_swap` and its dependencies (`libft`, `ft_printf`).

```bash
make clean    # remove object files
make fclean   # remove objects + binary
make re       # full rebuild
```

### Execution

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
```

**Examples:**

```bash
./push_swap 3 1 2 5 4
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23
./push_swap --bench --adaptive 4 67 3 87 23
```

**Strategy flags:**

| Flag | Algorithm | Complexity |
|------|-----------|------------|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk sort | O(n√n) |
| `--complex` | LSD Radix sort | O(n log n) |
| `--adaptive` | Auto-select by disorder | varies |

If no strategy flag is given, `--adaptive` is the default.

**`--bench` flag** prints sorting statistics to stderr after running (disorder %, strategy used, total ops, per-operation counts).

### Error cases

The program writes `Error` to stderr and exits on:
- Non-integer arguments
- Integers outside the int range
- Duplicate values

---

## Algorithm Details and Justification

### Disorder metric

Before sorting, the program computes a **disorder value** in [0, 1]:

```
disorder = (number of inverted pairs) / (total pairs)
```

An inverted pair is any `(i, j)` where `i < j` but `a[i] > a[j]`. This is computed in O(n²) on the initial input before any moves.

### Coordinate compression (ranks)

All three sorting algorithms operate on **ranks** (0-based integer positions in the sorted order) rather than raw values. This is computed once during parsing using an O(n²) counting pass. This ensures:
- The radix sort works correctly on negative numbers (ranks are always ≥ 0).
- The chunk sort divides the value space evenly regardless of the input range.

### Strategy 1 — Simple: Selection Sort — O(n²)

**How it works:** Each iteration finds the minimum-value element in stack a, rotates it to the top (using `ra` or `rra` choosing the shorter direction), then pushes it to b. After all elements are in b (in reverse sorted order), they are pushed back to a one by one.

**Why O(n²):** Each of the n iterations may rotate up to n/2 elements → n × n/2 = O(n²) operations.

**When used:** Disorder < 0.2 in adaptive mode. For nearly-sorted stacks, few inversions exist so the minimum is usually near the top, keeping the constant factor low.

### Strategy 2 — Medium: Chunk Sort — O(n√n)

**How it works:** Divide the rank range [0, n) into chunks of size ≈ √n. Scan stack a repeatedly: push any element whose rank falls in the current chunk window to b (using `rb` to keep larger elements closer to top within the chunk). Repeat until all chunks are pushed. Then restore b → a by repeatedly finding the maximum-rank element in b and rotating it to the top before pushing to a.

**Why O(n√n):** There are √n chunks. Per chunk, we scan a (at most n rotations) to push √n elements. Total push phase: √n × n = O(n√n). Restore phase: √n elements per chunk × √n chunks × O(√n) rotations per element = O(n√n).

**When used:** 0.2 ≤ disorder < 0.5 in adaptive mode.

### Strategy 3 — Complex: LSD Radix Sort — O(n log n)

**How it works:** Operates on 0-based ranks. For each bit position from LSB to MSB (log₂(n) passes):
- Iterate through all n elements of a: if the current bit of the element's rank is 0, push to b; if 1, rotate to bottom of a (`ra`).
- Push everything from b back to a (`pa`).

After log₂(n) passes, a is sorted in ascending rank order.

**Why O(n log n):** log₂(n) passes × n operations per pass = O(n log n).

**Why ranks (not raw values):** Ranks are always in [0, n-1], so we always need exactly ⌈log₂(n)⌉ bits. Raw values could be negative or span INT_MIN..INT_MAX, making bitwise operations unreliable.

**When used:** Disorder ≥ 0.5 in adaptive mode (highly disordered input).

### Strategy 4 — Adaptive

Measures disorder before sorting and delegates:
- disorder < 0.2 → simple_sort (O(n²))
- 0.2 ≤ disorder < 0.5 → medium_sort (O(n√n))
- disorder ≥ 0.5 → complex_sort (O(n log n))

**Rationale for thresholds:** A low-disorder stack (few inversions) means the minimum is often near the top, so the O(n²) selection sort has a small constant and avoids overhead. At medium disorder, chunk sort balances scan cost against chunk size. At high disorder, only the O(n log n) radix sort reliably meets the operation count benchmarks.

### Space complexity

All strategies use O(1) extra memory beyond the two stacks themselves (no auxiliary arrays during sorting). The rank computation during parsing uses O(n) space.

---

## Contributions

| Login | Contributions |
|-------|--------------|
| gogalsty | Stack implementation, all operations, parser, sorting algorithms, benchmark mode |
| [login2] | [describe contributions] |

---

## Resources

- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching*
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer) — useful for debugging operation sequences
- [42 push_swap guide (Medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Radix sort explained](https://en.wikipedia.org/wiki/Radix_sort)
- [Inversion count / disorder metric](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

### AI usage

Claude (Anthropic) was used to:
- Identify compilation errors and type mismatches in the initial codebase
- Review and fix the sorting algorithm implementations (especially radix sort on negative numbers)
- Help write and review this README

All generated code was reviewed, understood, and tested by both team members before inclusion.
