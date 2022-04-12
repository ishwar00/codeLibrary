#include <bits/stdc++.h>
using namespace std;

int amt_cases;
int AA;

vector<queue<int>> men_pref(501);
vector<vector<int>> women_pref(501, vector<int>(501));

deque<int> proposers;

vector<int> wifes(501);
vector<int> husbands(501, 0);

bool has_more_pref_than_cur(int woman, int man) {
    int possible_new_man_pref = women_pref[woman][man];
    int cur_man_pref = women_pref[woman][husbands[woman]];

    return (possible_new_man_pref > cur_man_pref);
}

void propose_and_reject() {
    while (!proposers.empty()) {
        int cur_man = proposers.front();

        if (men_pref[cur_man].empty()) {
            proposers.pop_front();
            continue;
        }

        int woman_to_propose = men_pref[cur_man].front();
        men_pref[cur_man].pop();

        if (husbands[woman_to_propose] == 0) {
            proposers.pop_front();

            wifes[cur_man] = woman_to_propose;
            husbands[woman_to_propose] = cur_man;
        } else if (has_more_pref_than_cur(woman_to_propose, cur_man)) {
            proposers.pop_front();
            proposers.push_back(husbands[woman_to_propose]);

            wifes[cur_man] = woman_to_propose;
            husbands[woman_to_propose] = cur_man;
        }
    }
}

void get_input() {
    cin >> AA;

    for (int i = 0; i < AA; i++) {
        int cur_woman;
        cin >> cur_woman;

        for (int j = 0, cur_pref = 4; j < AA; j++, cur_pref--) {
            int cur_man;
            cin >> cur_man;

            women_pref[cur_woman][cur_man] = AA - j;
        }
    }

    for (int i = 0; i < AA; i++) {
        int cur_man;
        cin >> cur_man;
        proposers.push_back(cur_man);
        men_pref[cur_man] = queue<int>();

        for (int j = 0; j < AA; j++) {
            int cur_woman;
            cin >> cur_woman;

            men_pref[cur_man].push(cur_woman);
        }
    }
}

int main() {
    cin >> amt_cases;

    for (int i = 0; i < amt_cases; i++) {
        get_input();

        propose_and_reject();
        for (int i = 1; i <= AA; i++) {
            cout << i << " " << wifes[i] << endl;

            wifes[i] = 0;
            husbands[i] = 0;
        }

    }

    return 0;
}