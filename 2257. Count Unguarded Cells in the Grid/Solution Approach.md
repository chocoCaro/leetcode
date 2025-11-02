# 2257. Count Unguarded Cells in the Grid

## Topics

- **Array**
- **Matrix**
- **Simulation**

## Solution Approach

1. Initialize a grid (2D array) filled with `0`.
2. Mark guards and walls by setting their cell value to `1`.
    > We use the same marker because guard positions also block further expansion, preventing multiple-counting.
3. Simulate each guard's line of sight:
    - Expand outward in the 4 cardinal directions (left, right, up, down).
    - Stop when reaching another guard or a wall (`1`).
    - Mark every visible cell as `2`, indicating it is guarded.
4. Count cells still `0` - these are unguarded cells.
