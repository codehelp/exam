# Assigment 4: Write a map-reduce program to count the number of occurrences of each alphabetic character in the given dataset. The count for each letter should be case-insensitive.

from collections import Counter
from multiprocessing import Pool

def mapper(chunk):
    counts = Counter(filter(str.isalpha, chunk.lower()))
    return counts

def reducer(counts_list):
    result = Counter()
    for counts in counts_list:
        result.update(counts)
    return result

data = "This is a sample dataset. Count the number of occurrences of each letter, case-insensitive."

# Splitting the dataset
chunk_size = len(data) // 4
chunks = [data[i:i + chunk_size] for i in range(0, len(data), chunk_size)]

# Pool creation of workers to perform mapping
with Pool() as pool:
    mapped_counts = pool.map(mapper, chunks)

# Reducing results from the mapper
final_counts = reducer(mapped_counts)

# Print the counts
for letter, count in sorted(final_counts.items()):
    print(f"{letter}: {count}")
