#include <iostream>
#include <chrono>
#include "Volume.h"
#include "legalChar.h"
#include "Queue.h"
#include "Stack.h"

bool IsPalindrom(Stack stack1, Stack stack2)
{
	int length = stack1.getLength(),
		length2 = stack2.getLength();
	if (length != length2) return false;
	if (length <= 1) return true;

	for (int i = 0; i < length / 2; i++)
		if (stack1.pop() != stack2.pop()) return false;

	return true;
}

bool IsPalindrom(Stack stack, Queue queue)
{
	int length = stack.getLength();
	if (length <= 1) return true;
	for (int i = 0; i < length / 2; i++)
	{
		char pop = stack.pop();
		char pop_back = queue.pop_back();
		if (pop_back != pop) return false;
	}
	return true;
}

int main()
{
	Stack stack1, stack2,
		stack3;
	Queue queue;
	char palindrom[] = "This is a Palindrom, or is it?";
	const int length = sizeof(palindrom) / sizeof(*palindrom);
	Volume vol[4][length];

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < length; i++)
		{
			if (j < 4)
			{
				//initialize
				vol[j][i] = Volume(palindrom[i]);

				//trim
				vol[j][i] = Volume(legalChar(vol[j][i].getData()));
			}
			else if (j == 4) // do once
			{
				//forwards
				stack1.push(&vol[0][i]);
				stack3.push(&vol[1][i]);

				//backwards
				queue.push_front(&vol[2][i]); // naturally
				stack2.push(&vol[3][length - 1 - i]);
			}
		}
	}

	bool isPalindrom1 = false;
	auto start1 = std::chrono::high_resolution_clock().now();
	isPalindrom1 = IsPalindrom(stack1, stack2);
	auto stop1 = std::chrono::high_resolution_clock::now();

	auto time_taken1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1).count();
	std::cout << "Your string is " << (isPalindrom1 ? "indeed" : "not") << " palindrom." << std::endl;
	std::cout << "Time taken for stack and stack: " << time_taken1 << " microseconds.\n";

	bool isPalindrom2 = false;
	auto start2 = std::chrono::high_resolution_clock().now();
	isPalindrom2 = IsPalindrom(stack3, queue);
	auto stop2 = std::chrono::high_resolution_clock().now();
	
	auto time_taken2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2).count();
	std::cout << "Your string is " << (isPalindrom2 ? "indeed" : "not") << " palindrom." << std::endl;
	std::cout << "Time taken for stack and queue: " << time_taken2 << " microseconds.\n";
}