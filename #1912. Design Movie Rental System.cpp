class MovieRentingSystem {
        using tuple = std::tuple<int, int, int>;
        using pair  = std::pair<int, int>;

    private:
        static constexpr int max = 5;

    private:
        std::vector<std::unordered_map<int, int>> m_shops;
        std::unordered_map<int, std::set<pair>>   m_movies;
        std::set<tuple>                           m_rents;

    public:
        MovieRentingSystem(int n, std::vector<std::vector<int>>& entries) : m_shops(n) {
            for (int i = 0, sz = entries.size(); i < sz; ++i) {
                auto [shop, movie, price] = std::make_tuple(entries[i][0], entries[i][1], entries[i][2]);
                m_shops[shop][movie] = price;
                auto it = m_movies.find(movie);
                if (it == m_movies.end())
                    it = m_movies.insert({ movie, std::set<pair>() }).first;
                it->second.insert(std::make_pair(price, shop));
            }
        }

        std::vector<int> search(int movie) {
            auto const& set = m_movies[movie];
            int count = 0;
            std::vector<int> ans;
            for (auto start = set.begin(), end = set.end(); start != end && count++ < max; ++start)
                ans.push_back(start->second);
            return ans;
        }

        void rent(int shop, int movie) {
            int price = m_shops[shop][movie];
            m_movies[movie].erase(std::make_pair(price, shop));
            m_rents.insert(std::make_tuple(price, shop, movie));
        }

        void drop(int shop, int movie) {
            int price = m_shops[shop][movie];
            m_rents.erase(std::make_tuple(price, shop, movie));
            m_movies[movie].insert(std::make_pair(price, shop));
        }

        std::vector<std::vector<int>> report() {
            std::vector<std::vector<int>> ans;
            int count = 0;
            for (auto start = m_rents.begin(), end = m_rents.end(); start != end && count++ < max; ++start) {
                auto const& [price, shop, movie] = *start;
                ans.emplace_back(std::vector<int>{shop, movie});
            }
            return ans;
        }
    };

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */