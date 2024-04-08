#include<iostream>
using namespace std;

//��֤���Ĵ�
bool isPalindrome(char* s) {
    char c[200000];
    int cur = 0;
    int i = 0;
    while (s[cur] != '\0')
    {
        if (s[cur] >= 'A' && s[cur] <= 'Z' || s[cur] >= 'a' && s[cur] <= 'z' || s[cur] >= '0' && s[cur] <= '9')
        {
            if (s[cur] >= 'A' && s[cur] <= 'Z')
            {
                s[cur] += 32;
            }
            c[i] = s[cur];
            i++;
        }
        cur++;
    }
    c[i] = '\0';
    int left = 0;
    int right = i - 1;
    while (left < right)
    {
        if (c[left] != c[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

//ֻ����һ�ε�����
int singleNumber(int* nums, int numsSize) {
    int j = nums[0];
    for (int i = 1;i < numsSize;i++)
    {
        j ^= nums[i];
    }
    return j;
}

//����Ԫ��
int majorityElement(int* nums, int numsSize) {
    int max = nums[0];
    int maxi = 1;
    for (int i = 1;i < numsSize;i++)
    {
        if (nums[i] == max)
        {
            maxi++;
        }
        else
        {
            maxi--;
            if (maxi < 0)
            {
                max = nums[i];
                maxi = 1;
            }
        }
    }
    return max;
}

//λ1������
int hammingWeight(int n) {
    int count = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

bool isHappy(int n) {
    int sum = 0;
    int count = 0;
    while (n != 1)
    {
        while (n != 0)
        {
            count++;
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if (count == 1000)
        {
            return false;
        }
        n = sum;
        sum = 0;
    }
    return true;
}


int main()
{
    int n = 0;
    cin >> n;
    bool i = isHappy(n);
    cout << i;
    return 0;
}