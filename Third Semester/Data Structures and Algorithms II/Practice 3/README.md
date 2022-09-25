## Sorting Algorithms Part III

### Counting Sort

Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence.

python code:

```python
def counting_sort(arr, max_val):
    m = max_val + 1
    count = [0] * m                
    for a in arr:
        count[a] += 1             
    i = 0
    for a in range(m):            
        for c in range(count[a]):  
            arr[i] = a
            i += 1
    return arr
```

### Radix Sort

Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value (place value). A positional notation is required, but because integers can represent strings of characters (e.g., names or dates) and specially formatted floating point numbers, radix sort is not limited to integers.

python code:

```python
def radix_sort(arr):
    RADIX = 10
    placement = 1
    max_digit = max(arr)
    while placement < max_digit:
        buckets = [list() for _ in range( RADIX )]
        for i in arr:
            tmp = int((i / placement) % RADIX)
            buckets[tmp].append(i)
        a = 0
        for b in range( RADIX ):
            buck = buckets[b]
            for i in buck:
                arr[a] = i
                a += 1
        placement *= RADIX
    return arr
```