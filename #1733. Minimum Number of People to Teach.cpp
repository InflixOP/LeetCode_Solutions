class Solution {
private:
    bool commonLanguage(int friend1, int friend2,
                        vector<vector<int>>& languages) {
        for (int x : languages[friend1])
            for (int y : languages[friend2])
                if (x == y)
                    return true;

        return false;
    }

    bool knownLangauge(int user, int language, vector<vector<int>>& languages) {
        for (int x : languages[user])
            if (language == x)
                return true;
        return false;
    }

public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        unordered_set<int> needTeaching;

        for (const auto& friendship : friendships) {
            int friend1 = friendship[0] - 1, friend2 = friendship[1] - 1;

            if (!commonLanguage(friend1, friend2, languages)) {
                needTeaching.insert(friend1);
                needTeaching.insert(friend2);
            }
        }

        int minimumTeachings = languages.size() + 1;

        for (int possibleLanguage = 1; possibleLanguage <= n;
             possibleLanguage++) {
            int teachingCounter = 0;
            for (int user : needTeaching) {
                if (!knownLangauge(user, possibleLanguage, languages))
                    teachingCounter++;
            }

            minimumTeachings = min(minimumTeachings, teachingCounter);
        }

        return minimumTeachings;
    }
};