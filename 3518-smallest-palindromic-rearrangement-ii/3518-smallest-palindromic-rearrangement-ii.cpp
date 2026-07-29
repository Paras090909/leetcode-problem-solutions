class Solution {
public:
    using ll = long long;

    ll nCr(int n, int r, int k) {
        ll res = 1;
        r = min(r, n - r);

        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;

            if (res > k)
                return (ll)k + 1;
        }

        return res;
    }

    ll ways(int n, vector<int>& freq, int k) {
        ll total = 1;

        for (int i = 0; i < 26; i++) {
            total *= nCr(n, freq[i], k);

            if (total > k)
                return (ll)k + 1;

            n -= freq[i];
        }

        return total;
    }

    string smallestPalindrome(string s, int k) {

        int n = s.size();
        int len = n / 2;

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string ans(n, ' ');

        // Middle character (if odd length)
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                ans[n / 2] = char('a' + i);

            freq[i] /= 2;
        }

        ll totalWays = ways(len, freq, k);

        if (totalWays < k)
            return "";

        // Construct first half
        for (int idx = 0; idx < len; idx++) {

            for (int ch = 0; ch < 26; ch++) {

                if (freq[ch] == 0)
                    continue;

                freq[ch]--;

                ll possible = ways(len - idx - 1, freq, k);

                if (possible >= k) {

                    ans[idx] = char('a' + ch);
                    break;

                } else {

                    k -= possible;
                    freq[ch]++; // undo
                }
            }
        }

        // Mirror
        for (int i = 0; i < len; i++)
            ans[n - i - 1] = ans[i];

        return ans;
    }
};