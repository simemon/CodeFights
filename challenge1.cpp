/*
The difference between two sequences of the same length a1, a2, a3,..., an and b1, b2, b3,..., bn can be defined as the sum of absolute differences between their respective elements:

diff(a, b) = |a1 - b1| + |a2 - b2| + ... + |an - bn|.

For the given sequences a and b (not necessarily having the same lengths) find a subsequence b' of b such that diff(a, b') is minimal. Return this difference.

Example

For a = [1, 2, 6] and b = [0, 1, 3, 4, 5], the output should be
closestSequence2(a, b) = 2.

The best subsequence will be b' = [1, 3, 5] which has a difference of 2 with a.

Input/Output

[time limit] 500ms (cpp)
[input] array.integer a

Constraints:
3 ≤ a.length ≤ 1000,
-1000 ≤ a[i] ≤ 1000.

[input] array.integer b

Constraints:
a.length ≤ b.length ≤ 1000,
-1000 ≤ b[i] ≤ 1000.

[output] integer
*/

int closestSequence2(std::vector<int> a, std::vector<int> b) 
{
    int al = a.size();
    int bl = b.size();
    std::vector<std::vector<int> >  matrix (al, std::vector<int> (bl, INT_MAX));
    for(int i = 0; i < al; ++i)
    {
        for(int j = 0; j < bl; ++j)
        {
            if(j >= i and (bl - j) >= (al -i))
            {
                int temp;
                if(i == 0 and j == 0)
                    matrix[i][j] = abs(a[i] - b[j]);
                else
                {    
                    if(i  == 0 || j == 0)
                        temp = abs(a[i] - b[j]);
                    else
                        temp = abs(a[i] - b[j]) + matrix[i-1][j-1];
                    matrix[i][j] = std::min(temp, matrix[i][j-1]);
                }
            }
        }
    }
    return matrix[al-1][bl-1];
}

