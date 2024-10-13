#include <bits/stdc++.h>

using namespace std;

class MinHeapNode
{
public:
	char data;
	int freq;
	MinHeapNode *left;
	MinHeapNode *right;

	MinHeapNode(char data, int freq)
	{
		this->data = data;
		this->freq = freq;
		left = right = nullptr;
	}
};

class HuffmanCoding
{
public:
	void printCodes(MinHeapNode *root, string str)
	{
		if (root == nullptr)
		{
			return;
		}
		if (root->data != '$')
		{
			cout << root->data << ": " << str << endl;
		}
		printCodes(root->left, str + "0");
		printCodes(root->right, str + "1");
	}

	void createHuffmanCode(char data[], int freq[], int size)
	{
		MinHeapNode *left, *right, *temp;

		priority_queue<MinHeapNode *, vector<MinHeapNode *>, Compare> minHeap;

		for (int i = 0; i < size; i++)
		{
			minHeap.push(new MinHeapNode(data[i], freq[i]));
		}

		while (minHeap.size() != 1)
		{
			left = minHeap.top();
			minHeap.pop();
			right = minHeap.top();
			minHeap.pop();

			temp = new MinHeapNode('$', left->freq + right->freq);
			temp->left = left;
			temp->right = right;

			minHeap.push(temp);
		}
		printCodes(minHeap.top(), "");
	}

private:
	class Compare
	{
	public:
		bool operator()(MinHeapNode *a, MinHeapNode *b)
		{
			return (a->freq > b->freq);
		}
	};
};

int main()
{
	char data[] = {'A', 'B', 'C', 'D'};
	int freq[] = {23, 12, 34, 10};

	HuffmanCoding huffman;
	huffman.createHuffmanCode(data, freq, 4);

	return 0;
}
