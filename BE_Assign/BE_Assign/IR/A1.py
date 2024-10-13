# Assignment 1: Write a program to Compute Similarity between two text documents

import re
import string
from collections import Counter
import math

def preprocess_text(text):
    # Convert text to lowercase and remove punctuation
    text = text.lower()
    text = re.sub(f"[{re.escape(string.punctuation)}]", "", text)
    return text

def compute_cosine_similarity(doc1, doc2):
    # Preprocessing
    doc1 = preprocess_text(doc1)
    doc2 = preprocess_text(doc2)

    # Tokenization
    doc1_words = doc1.split()
    doc2_words = doc2.split()

    # Set of unique words in both documents
    words = set(doc1_words + doc2_words)

    # Counters creation
    doc1_word_counts = Counter(doc1_words)
    doc2_word_counts = Counter(doc2_words)

    # Calculate the dot product and magnitudes of both documents
    dot_product = sum(doc1_word_counts[word] * doc2_word_counts[word] for word in words)
    magnitude_doc1 = math.sqrt(sum(doc1_word_counts[word] ** 2 for word in words))
    magnitude_doc2 = math.sqrt(sum(doc2_word_counts[word] ** 2 for word in words))

    # Cosine similarity Calculation
    similarity = dot_product / (magnitude_doc1 * magnitude_doc2)

    return similarity

if __name__ == "__main__":
    # Example 
    document1 = "This is a sample document for computing document similarity."
    document2 = "You can compute document similarity using various techniques like Cosine Similarity."

    # Computing cosine similarity between the two documents
    similarity = compute_cosine_similarity(document1, document2)
    print(f"Cosine Similarity between the two documents: {similarity:.2f}")
