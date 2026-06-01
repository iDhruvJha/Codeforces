#include <bits/stdc++.h>
using namespace std::ranges;

#include <ext/pb_ds/assoc_container.hpp>
template <class K, class Cmp = std::less<K>>
using indexed_set = __gnu_pbds::tree<K, __gnu_pbds::null_type, Cmp, __gnu_pbds::rb_tree_tag,
                                     __gnu_pbds::tree_order_statistics_node_update>;

using std::cin, std::cout;
static const bool io_boost = [] -> bool {
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << std::fixed << std::setprecision(12);
  return std::ios_base::sync_with_stdio(false);
}();

template <class T>
concept StreamReadable = requires(std::istream &is, T &t) { is >> t; };
template <class T>
concept StreamWritable = requires(std::ostream &os, T const &t) { os << t; };
template <class T>
concept Iterable = requires(T t) {
  std::begin(t);
  std::end(t);
};
template <class T>
concept TupleLike = requires { typename std::tuple_size<T>::type; };

struct Reader {
  template <class T>
  void read(T &t) {
    if constexpr (StreamReadable<T>) {
      cin >> t;
    } else if constexpr (Iterable<T>) {
      for (auto &x : t)
        read(x);
    } else if constexpr (TupleLike<T>) {
      std::apply([this](auto &...args) { (read(args), ...); }, t);
    } else {
      static_assert(sizeof(T) == 0, "Unsupported type");
    }
  }

  template <class... Ts>
  void operator()(Ts &...ts) {
    (read(ts), ...);
  }
};

struct Writer {
  template <class T>
  void write(T const &t) const {
    if constexpr (StreamWritable<T>) {
      cout << t;
    } else if constexpr (Iterable<T>) {
      bool first = true;
      for (auto const &x : t) {
        if (!first)
          cout << ' ';
        first = false;
        write(x);
      }
    } else if constexpr (TupleLike<T>) {
      // clang-format off
      std::apply([this](auto const&... args) {
        bool first = true;
        ((cout << (first ? "" : " "), write(args), first = false), ...);
      }, t);
      // clang-format on
    } else {
      static_assert(sizeof(T) == 0, "Unsupported type");
    }
  }

  template <class... Ts>
  void operator()(Ts const &...ts) const {
    bool first = true;
    ((cout << (first ? "" : " "), write(ts), first = false), ...);
    cout << '\n';
  }
};

Reader re;
Writer wr;

template <contiguous_range R>
auto slice(R &&r, size_t l, size_t h) {
  assert(l < h && "Invalid range");
  return std::span(data(r) + l, h - l);
}

void yes(bool c = true) { wr(c ? "YES" : "NO"); }

using str = std::string;
template <class T>
using vec = std::vector<T>;
template <class T>
using prq = std::priority_queue<T>;
template <class T>
using pqg = std::priority_queue<T, std::vector<T>, std::greater<>>;
template <class K, class V>
using umap = std::unordered_map<K, V>;
template <class T>
using uset = std::unordered_set<T>;

using u32 = uint32_t;
using u64 = uint64_t;
using i64 = int64_t;
using f32 = double;
using f64 = long double;
using u128 = __uint128_t;
using i128 = __int128_t;

void solve() {
  u32 n;
  re(n);
  vec<u32> a(n);
  re(a);
  sort(a, std::greater<u32>{});
  auto b = a;
  b.erase(std::unique(b.begin(), b.end()), b.end());
  if (b.size() != n) {
    wr(-1);
    return;
  }
  wr(a);
}

int main() {
  int t;
  re(t);
  while (t--)
    solve();
  return 0;
}