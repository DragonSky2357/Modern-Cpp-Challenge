

// 1
/*
#include<iostream>

int main(void) {
	unsigned int limit = 0;
	std::cout << "Upper limit:";
	std::cin >> limit;

	unsigned long long sum = 0;
	for (unsigned int i = 3; i < limit; ++i)
		if (i % 3 == 0 || i % 5 == 0) sum += i;

	std::cout << "sum=" << sum << std::endl;
}
*/

/*
// 2
// 최대공약수 재귀 함수
unsigned int gcd(unsigned int const a, unsigned int const b) {
	return b == 0 ? a : gcd(b, a % b);
}

// 최대공약수 비재귀 함수
unsigned int gcd2(unsigned int a, unsigned int b) {
	while (b != 0) {
		unsigned int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

// c++ 17이상 <numeric>헤더에서 gcd()함수 사용가능
*/

/*
// 3
// 최소 공배수
int lcm(int const a, int const b) {
	int h = gcd(a, b);
	return h ? (a * (b / n)) : 0;
}

template<class InputIt>
int lcmr(InputIt first, InputIt last) {
	return std::accumulate(first, last, 1, lcm);
}

// c++ 17이상 <numeric>헤더에서 lcm()함수 사용가능
*/

/*
// 4
// 주어진 수보다 작은 가장 큰 소수 계산

#include<iostream>

bool is_prime(const int num) {
	if (num <= 3) return num > 1;
	else if (num % 2 == 0 || num % 3 == 0) return false;
	else {
		for (int i = 5; i * i <= num; i += 6)
			if (num % i == 0 || num % (i + 2) == 0) return false;

		return true;
	}
}

int main(void) {
	int limit = 0;
	std::cout << "Upper limit:";
	std::cin >> limit;

	for (int i = limit; i > 1; i--) {
		if (is_prime(i)) {
			std::cout << "Largest prime:" << i << std::endl;
			return 0;
		}
	}
}
*/

/*
// 5
// 섹시 소수 짝을 출력

#include<iostream>

bool is_prime(const int num) {
	if (num <= 3) return num > 1;
	else if (num % 2 == 0 || num % 3 == 0) return false;
	else {
		for (int i = 5; i * i <= num; i += 6)
			if (num % i == 0 || num % (i + 2) == 0) return false;

		return true;
	}
}

int main(void) {
	int limit = 0;
	std::cout << "Upper limit:";
	std::cin >> limit;

	for (int n = 2; n <=limit; n++) {
		if (is_prime(n) && is_prime(n+6)){
			std::cout<<n<<","<<n+6<<std::endl;
			return 0;
		}
	}
}
*/

/*
// 6
// 과잉수 출력

#include<iostream>
#include<cmath>
int sum_proper_divisors(const int number) {
	int result = 1;
	for (int i = 2; i <= std::sqrt(number); i++) {
		if (number % i == 0)
			result += (i == (number / i)) ? i : (i + number / i);

	}
	return result;
}

void print_abundant(const int limit) {
	for (int number = 10; number <= limit; ++number) {
		auto sum = sum_proper_divisors(number);
		if (sum > number)
			std::cout << number << ", abundance=" << sum - number << std::endl;
	}
}

int main(void) {
	int limit = 0;
	std::cout << "Upper limit:";
	std::cin >> limit;

	print_abundant(limit);
}
*/

/*
// 7 친화수 짝

int sum_proper_divisors(const int number) {
	int result = 1;
	for (int i = 2; i <= std::sqrt(number); i++) {
		if (number % i == 0)
			result += (i == (number / i)) ? i : (i + number / i);

	}
	return result;
}

void print_amicables(const int limit) {
	for (int number = 4; number < limit; ++number) {
		auto sum1 = sum_proper_divisors(number);
		if (sum1 < limit) {
			auto sum2 = sum_proper_divisors(sum1);
			if (sum2 == number && number != sum1)
				std::cout << number << "," << sum1 << std::endl;
		}
	}
}
*/

/*
// 8 암스트롱 수 출력

void print_narcissistics(const bool printResults) {
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				auto abc = a * 100 + b * 10 + c;
				auto arm = a * a*a + b * b * b + c * c * c;
				if (abc == arm)
					std::cout << arm << std::endl;
			}
		}
	}
}
*/

/*
// 9 소인수 분해

#include<iostream>
#include<vector>

std::vector<unsigned long long> prime_factors(unsigned long long n) {
	std::vector<unsigned long long> factors;
	while (n % 2 == 0) {
		factors.push_back(2);
		n = n / 2;
	}

	for (unsigned long long i = 3; i <= std::sqrt(n); i += 2) {
		while (n % i == 0) {
			factors.push_back(i);
			n = n / i;
		}
	}

	if (n > 2)
		factors.push_back(n);

	return factors;
}

int main(void) {
	unsigned long long number = 0;
	std::cout << "number:";
	std::cin >> number;
	auto factors = prime_factors(number);
	std::copy(std::begin(factors), std::end(factors), std::ostream_iterator<unsigned long long>(std::cout, " "));
}
*/

/*
// 10 그레이 코드

#include<iostream>
#include<bitset>
unsigned int gray_encode(unsigned const int num) {
	return num ^ (num >> 1);
}

unsigned int gray_decode(unsigned int gray) {
	for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1)
		if (gray & bit) gray ^= bit >> 1;

	return gray;
}

std::string to_binary(unsigned int value, const int digits) {
	return std::bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main(void) {
	std::cout << "Number\tBinary\tGray\tDecode\n";
	std::cout << "-----\t-----\t-----\t-----\n";

	for (unsigned int n = 0; n < 32; n++) {
		auto encg = gray_encode(n);
		auto decg = gray_decode(encg);

		std::cout << n << "\t" << to_binary(n, 5) << "\t" << to_binary(encg, 5) << "\t" << decg << "\n";
	}
}
*/

/*
// 11 로마 숫자 표기법 변환
#include<iostream>
#include<vector>

std::string to_roman(unsigned int value) {
	std::vector<std::pair<unsigned int, char const*>> roman{
		{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
		{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
		{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"} };

	std::string result;
	for (auto const& kvp : roman) {
		while (value >= kvp.first) {
			result += kvp.second;
			value -= kvp.first;
		}
	}
	return result;
}

int main(void) {
	for (int i = 0; i <= 100; i++)
		std::cout << i << "\t" << to_roman(i) << std::endl;

	int number = 0;
	std::cout << "number";
	std::cin >> number;
	std::cout << to_roman(number) << std::endl;
}
*/

/*
// 12 가장 긴 콜라츠 수열 출력

#include<iostream>
#include<vector>

std::pair<unsigned long long, long>longest_collatz(unsigned const long long limit) {
	long length = 0;
	unsigned long long number = 0;
	std::vector<int> cache(limit + 1, 0);

	for (unsigned long long i = 2; i <= limit; i++) {
		auto n = i;
		long steps = 0;

		while (n != 1 && n >= i) {
			if ((n % 2) == 0) n /= 2;
			else n = n * 3 + 1;
			steps++;
		}
		cache[i] = steps + cache[n];

		if (cache[i] > length) {
			length = cache[i];
			number = i;
		}
	}
	return std::make_pair(number, length);
}
*/

/*
// 13 파이 값 계산
#include <random>
#include<array>
#include<iostream>

template<typename E = std::mt19937, typename D=std::uniform_real_distribution<>>
double compute_pi(E& engine, D& dist, const int samples = 1000000) {
	auto hit = 0;
	for (auto i = 0; i < samples; i++) {
		auto x = dist(engine);
		auto y = dist(engine);
		if (y <= std::sqrt(1 - std::pow(x, 2))) hit++;
	}
	return 4.0 * hit / samples;
}

int main(void) {
	std::random_device rd;
	auto seed_data = std::array<int, std::mt19937::state_size>{};
	std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
	std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
	auto eng = std::mt19937{ seq };
	auto dist = std::uniform_real_distribution<>{ 0,1 };

	for (auto j = 0; j < 10; j++)
		std::cout << compute_pi(eng, dist) << std::endl;
}
*/

/*
// 14 ISBN 검증

#include <string_view>
bool validate_isbn(std::string_view isbn) {
	auto valid = false;
	if (isbn.size() == 10 &&
		std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10) {
		auto w = 10;
		auto sum = std::accumulate(std::begin(isbn), std::end(isbn), 0,
			[&w](const int total, const char c) {
				return total + w-- * (c - '0');});

		valid = !(sum % 11);
	}
	return valid;
}
*/

/*
// 15 IPv4 데이터 형식 표현

#include<iostream>
#include<array>
#include<sstream>
#include<assert.h>

class ipv4 {
	std::array<unsigned char, 4> data;

public:
	constexpr ipv4():data{{0}}{}
	constexpr ipv4(unsigned const char a, unsigned const char b,
					unsigned const char c, unsigned const char d):
		data{{a,b,c,d}}{ }
	explicit constexpr ipv4(unsigned long a):
		data{{static_cast<unsigned char>((a>>24) & 0xFF),
			static_cast<unsigned char>((a >> 16) & 0xFF),
			static_cast<unsigned char>((a >> 8) & 0xFF),
			static_cast<unsigned char>(a & 0xFF)}}{}
	ipv4(ipv4 const& other) noexcept : data(other.data){}
	ipv4& operator=(ipv4 const& other) noexcept {
		data = other.data;
		return *this;
	}

	std::string to_string() const {
		std::stringstream sstr;
		sstr << *this;
		return sstr.str();
	}

	constexpr unsigned long to_ulong() const noexcept {
		return (static_cast<unsigned long>(data[0]) << 24) |
				(static_cast<unsigned long>(data[1]) << 16) |
				(static_cast<unsigned long>(data[2]) << 8)|
				static_cast<unsigned long>(data[3]);
	}

	friend std::ostream& operator<<(std::ostream& os, const ipv4& a) {
		os << static_cast<int>(a.data[0]) << '.'
			<< static_cast<int>(a.data[1]) << '.'
			<< static_cast<int>(a.data[2]) << '.'
			<< static_cast<int>(a.data[3]);

		return os;
	}

	friend std::istream& operator>>(std::istream& is, ipv4& a) {
		char d1, d2, d3;
		int b1, b2, b3, b4;

		is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;

		if (d1 == '.' && d2 == '.' && d3 == '.') a = ipv4(b1, b2, b3, b4);
		else is.setstate(std::ios_base::failbit);

		return is;
	}
};

int main(void) {
	ipv4 address(168, 192, 0, 1);
	std::cout << address << std::endl;

	ipv4 ip;
	std::cout << ip << std::endl;
	std::cin >> ip;
	if (!std::cin.fail())
		std::cout << ip << std::endl;
}
*/

/*
// 16 범위 안에 있는 IPv4 주소 열서

#include<iostream>
#include<array>
#include<sstream>
#include<assert.h>

class ipv4 {
	std::array<unsigned char, 4> data;

public:
	constexpr ipv4() :data{ {0} } {}
	constexpr ipv4(unsigned const char a, unsigned const char b,
		unsigned const char c, unsigned const char d) :
		data{ {a,b,c,d} } {
	}
	explicit constexpr ipv4(unsigned long a) :
		data{ {static_cast<unsigned char>((a >> 24) & 0xFF),
			static_cast<unsigned char>((a >> 16) & 0xFF),
			static_cast<unsigned char>((a >> 8) & 0xFF),
			static_cast<unsigned char>(a & 0xFF)} } {
	}
	ipv4(ipv4 const& other) noexcept : data(other.data) {}
	ipv4& operator=(ipv4 const& other) noexcept {
		data = other.data;
		return *this;
	}

	std::string to_string() const {
		std::stringstream sstr;
		sstr << *this;
		return sstr.str();
	}

	constexpr unsigned long to_ulong() const noexcept {
		return (static_cast<unsigned long>(data[0]) << 24) |
			(static_cast<unsigned long>(data[1]) << 16) |
			(static_cast<unsigned long>(data[2]) << 8) |
			static_cast<unsigned long>(data[3]);
	}

	friend std::ostream& operator<<(std::ostream& os, const ipv4& a) {
		os << static_cast<int>(a.data[0]) << '.'
			<< static_cast<int>(a.data[1]) << '.'
			<< static_cast<int>(a.data[2]) << '.'
			<< static_cast<int>(a.data[3]);

		return os;
	}

	friend std::istream& operator>>(std::istream& is, ipv4& a) {
		char d1, d2, d3;
		int b1, b2, b3, b4;

		is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;

		if (d1 == '.' && d2 == '.' && d3 == '.') a = ipv4(b1, b2, b3, b4);
		else is.setstate(std::ios_base::failbit);

		return is;
	}

	ipv4& operator++() {
		*this = ipv4(1 + to_ulong());
		return *this;
	}

	ipv4& operator++(int) {
		ipv4 result(*this);
		++(*this);
		return result;
	}

	friend bool operator==(const ipv4& a1, const ipv4& a2) noexcept {
		return a1.data == a2.data;
	}

	friend bool operator!=(const ipv4& a1, const ipv4& a2) noexcept {
		return !(a1 == a2);
	}

	friend bool operator<(const ipv4& a1, const ipv4& a2) noexcept {
		return a1.to_ulong() < a2.to_ulong();
	}

	friend bool operator>(const ipv4& a1, const ipv4& a2) noexcept {
		return a2 < a1;
	}

	friend bool operator<=(const ipv4& a1, const ipv4& a2) noexcept {
		return !(a1 > a2);
	}
};

int main(void) {
	std::cout << "input range: ";
	ipv4 a1, a2;
	std::cin >> a1 >> a2;
	if (a2 > a1) {
		for (ipv4 a = a1; a <= a2; a++)
			std::cout << a << std::endl;
	} else {
		std::cerr << "invalid range!" << std::endl;
	}
}
*/

/*
// 17 기본적인 연산을 지원하는 2차원 배열

#include<iostream>
#include<vector>
using namespace std;

template<typename T, size_t R, size_t C>
class array2d {
	typedef T value_type;
	typedef value_type* iterator;
	typedef const value_type* const_iterator;
	std::vector<T> arr;

public:
	array2d() : arr(R*C){}
	explicit array2d(std::initializer_list<T> l):arr(l){}
	constexpr  T* data() noexcept { return arr.data(); }
	constexpr T const* data() const noexcept { return arr.data(); }

	constexpr T& at(const size_t r, const size_t c) {
		return arr.at(r * C * C);
	}

	constexpr T const&  at(const size_t r, const size_t c)const {
		return arr.at[r * C + c];
	}

	constexpr T& operator()(const size_t r, const size_t c) {
		return arr[r * C + c];
	}

	constexpr T const&  operator()(const size_t r, const size_t c)const {
		return arr[r * C + c];
	}

	constexpr bool empty() const noexcept { return R == 0 || C == 0; }

	constexpr size_t size(const int rank) const {
		if (rank == 1) return R;
		else if (rank == 2) return C;
		throw std::out_of_range("Rank is out of range!");
	}

	void fill(T const& value) {
		std::fill(std::begin(arr), std::end(arr), value);
	}

	void swap(array2d& other) noexcept { arr.swap(other.arr); }

	const_iterator begin() const { return arr.data(); }
	const_iterator end() const { return arr.data() + arr.size(); }
	iterator begin() { return arr.data(); }
	iterator end() { return arr.data() + arr.size(); }
};

int main(void) {
	array2d<int, 2, 3> a{ 1,2,3,4,5,6 };
	for (size_t i = 0; i < a.size(1); ++i)
		for (size_t j = 0; j < a.size(2); ++j)
			a(i, j) *= 2;

	std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));

	array2d<int, 2, 3> b;
	b.fill(1);

	a.swap(b);

	array2d<int, 2, 3> c(std::move(b));
}
*/

/*
// 18 여러 수를 인자로 받는 최소 함수

#include <functional>
template<class Compare, typename T>
T minimumc(Compare comp, const T a, const T b) { return comp(a, b) ? a : b; }

template<class Compare, typename T1, typename... T>
T1 minimumc(Compare comp,T1 a, T... args) {
	return minimumc(comp,a, minimumc(comp,args...));
}

int main(void) {
	auto y = minimumc(std::less<>(),5, 4, 2, 3);
}
*/

/*
// 19 컨테이너에 여라 값 삽입 c++ 17이상

#include<vector>
#include<list>
#include<iostream>
template <typename C, typename... Args>
void push_back(C& c, Args&&... args) {
	(c.push_back(args), ...);
}

int main(void) {
	std::vector<int> v;
	push_back(v, 1, 2, 3, 4);
	std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, " "));

	std::list<int> l;
	push_back(l, 1, 2, 3, 4);
	std::copy(std::begin(l), std::end(l), std::ostream_iterator<int>(std::cout, " "));
}
*/

/*
// 20 컨테이너 안의 우너소를 조건별로 확인하는 함수 Helper function

template<class C, class T>
bool contains(const C& c, const T& vlaue) {
	return std::end(c) != std::find(std::begin(c), std::end(c), value);
}

template<class C, class... T>
bool contains_any(const C& c, T&&... value) {
	return(... || contains(c, value));
}

template<class C, class... T>
bool contains_all(const C& c, T&&... value) {
	return (... && contains(c, value));
}

template <class C, class... T>
bool contains_none(const C& c, T&&... value) {
	return !contains_any(c, std::forward<T>(value)...);
}
*/

/*
// 21 시스템 핸들 래퍼

#include<Windows.h>
#include<vector>

void bad_handle_example() {
	bool condition1 = false;
	bool condition2 = true;
	HANDLE handle = CreateFile(TEXT("sample.txt"),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);

	if (handle == INVALID_HANDLE_VALUE)
		return;

	if (condition1) {
		CloseHandle(handle);
		return;
	}

	std::vector<char> buffer(1024);
	unsigned long bytesRead = 0;
	ReadFile(handle, buffer.data(), buffer.size(), &bytesRead, nullptr);

	if (condition2) return;

	function_that_throws();

	CloseHandle(handle);
}

template<typename Traits>
class unique_handle {
	using pointer = typename Traits::pointer;
	pointer m_value;

public:
	unique_handle(const unique_handle&) = delete;
	unique_handle& operator=(const unique_handle&) = delete;

	explicit unique_handle(pointer value = Traits::invalid()) noexcept
		:m_value{value}
	{ }

	unique_handle(unique_handle&& other) noexcept
		:m_value{other.release()}
	{ }

	unique_handle& operator=(unique_handle&& other) noexcept {
		if (this != &other)
			reset(other.release());
		return *this;
	}

	~unique_handle() noexcept {
		Traits::close(m_value);
	}

	explicit operator bool() const noexcept {
		return m_value != Traits::invalid();
	}

	pointer get() const noexcept { return m_value; }

	pointer release() noexcept {
		auto value = m_value;
		m_value = Traits::invalid();
		return value;
	}

	bool reset(pointer value = Traits::invalid()) noexcept {
		if (m_value != value) {
			Traits::close(m_value);
			m_value = value;
		}
		return static_cast
	}

	void swap(unique_handle<Traits>& other) noexcept {
		std::swap(m_value, other.m_value);
	}
};

template<typename Traits>
void swap(unique_handle<Traits>& left, unique_handle<Traits>& right) noexcept {
	left.swap(right);
}

template<typename Traits>
bool operator==(unique_handle<Traits> const& left, unique_handle<Traits> const& right) noexcept {
	return left.get() == right.get();
}

template<typename Traits>
bool operator!=(unique_handle<Traits> const& left, unique_handle<Traits> const& right) noexcept {
	return left.get() != right.get();
}

struct null_handle_traits {
	using pointer = HANDLE;
	static pointer invalid() noexcept { return nullptr; }
	static void close(pointer value) noexcept {
		CloseHandle(value);
	}
};

struct invalid_handle_traits {
	using pointer = HANDLE;
	static pointer invalid() noexcept { return INVALID_HANDLE_VALUE; }
	static void close(pointer value)noexcept {
		CloseHandle(value);
	}
};

using null_handle = unique_handle<null_handle_traits>;
using invalid_handle = unique_handle<invalid_handle_traits>;

void good_handle_example() {
	bool condition1 = false;
	bool condition2 = true;
	invalid_handle handle{ CreateFile(TEXT("sample.txt"), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr) };

	if (!handle) return;
	if (condition1) return;

	std::vector<char> buffer(1024);
	unsigned long bytesRead = 0;
	ReadFile(handle.get(), buffer.data(), buffer.size(), &bytesRead, nullptr);

	if (condition2) return;

	function_that_throws();
}
*/

/*
// 22 온도 단위 리터럴 제공 라이브러리

#include<iostream>

bool are_equal(const double d1, const double d2, const double epsilon = 0.001) {
	return std::fabs(d1 - d2) < epsilon;
}

namespace temperature {
	enum class scale{celsius,fahrenheit,kelvin};

	template<scale S>
	class quantity {
		const double amout;
	public:
		constexpr explicit quantity(const double a):amout(a){}
		explicit operator double() const { return amout; }
	};
}

namespace temperature {
	template<scale S>
	inline bool operator==(const quantity<S>& lhs, const quantity<S>& rhs) {
		return are_equal(static_cast<double>(lhs), static_cast<double>(rhs));
	}

	template<scale S>
	inline bool operator!=(const quantity<S>& lhs, const quantity<S>& rhs) {
		return !(lhs == rhs);
	}

	template<scale S>
	inline bool operator<(const quantity<S>& lhs, const quantity<S>& rhs) {
		return static_cast<double>(lhs) < static_cast<double>(rhs);
	}

	template<scale S>
	inline bool operator>(const quantity<S>& lhs, const quantity<S>& rhs) {
		return rhs < lhs;
	}

	template<scale S>
	inline bool operator<=(const quantity<S>& lhs, const quantity<S>& rhs) {
		return !(rhs > lhs);
	}

	template<scale S>
	inline bool operator>=(const quantity<S>& lhs, const quantity<S>& rhs) {
		return !(rhs < lhs);
	}

	template<scale S>
	constexpr quantity<S> operator+(const quantity<S>& q1, const quantity<S>& q2) {
		return quantity<S>(static_cast<double>(q1) + static_cast<double>(q2));
	}
	template<scale S>
	constexpr quantity<S> operator-(const quantity<S>& q1, const quantity<S>& q2) {
		return quantity<S>(static_cast<double>(q1) - static_cast<double>(q2));
	}
}

namespace temperature {
	template<scale S, scale R>
	struct conversion_traits {
		static double convert(double const value) = delete;
	};

	template<>
	struct conversion_traits<scale::celsius, scale::fahrenheit> {
		static double convert(const double value) {
			return (value * 9) / 5 + 32;
		}
	};

	template<>
	struct conversion_traits<scale::fahrenheit, scale::celsius> {
		static double convert(const double value) {
			return (value - 32) * 5 / 9;
		}
	};

	template <scale R, scale S>
	constexpr quantity<R> temperature_cast(const quantity<S> q) {
		return quantity<R>(conversion_traits<S, R>::convert(static_cast<double>(q)));
	}
}

namespace temperature {
	namespace temperature_scale_literals {
		constexpr quantity<scale::celsius> operator "" _deg(const long double amount) {
			return quantity<scale::celsius>{static_cast<double>(amount) };
		}

		constexpr quantity<scale::celsius> operator "" _f(const long double amount) {
			return quantity<scale::fahrenheit>{static_cast > double > (amount)};
		}
	}
}

int main(void) {
	using namespace temperature;
	using namespace temperature_scale_literals;

	auto t1{ 36.5_deg };
	auto t2{ 79.0_f };

	auto tf = temperature_cast<scale::fahrenheit>(t1);
	auto tc = temperature_cast<scale::celsius>(tf);
	assert(t1 == tc);
}
*/

/*
// 23 바이너리 데이터를 문자열로 변환
#include <string>
#include<vector>
#include<array>
#include<cassert>
#include<ios>
#include<iomanip>

template<typename Iter>
std::string bytes_to_hexstr(Iter begin, Iter end, const bool uppercase = false) {
	std::ostringstream oss;
	if (uppercase) oss.setf(std::ios_base::uppercase);
	for (; begin != end; ++begin)
		oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*begin);
	return oss.str();
}

template<typename C>
std::string bytes_to_hexstr(const C& c, const bool uppercase = false) {
	return bytes_to_hexstr(std::cbegin(c), std::cend(c), uppercase);
}

int main(void) {
	std::vector<unsigned char> v{ 0xBA,0xAD,0xF0,0x0D };
	std::array<unsigned char, 6> a{ {1,2,3,4,5,6} };
	unsigned char buf[5] = { 0x11,0x22,0x33,0x44,0x55 };

	assert(bytes_to_hexstr(v, true) == "BAADF00D");
	assert(bytes_to_hexstr(a, true) == "010203040506");
	assert(bytes_to_hexstr(buf, true) == "1122334455");

	assert(bytes_to_hexstr(v, true) == "baadf00d");
	assert(bytes_to_hexstr(a, true) == "010203040506");
	assert(bytes_to_hexstr(buf, true) == "1122334455");
}
*/

/*
// 24 문자열을 바이너리 데이터로 변환

#include<stdexcept>
#include<vector>
#include<cassert>
unsigned char hexchar_to_int(const char ch) {
	if (ch >= '0' && ch <= '9') return ch - '0';
	if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
	if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
		throw std::invalid_argument("Invalid hexadecimal character");
}

std::vector<unsigned char> hexstr_to_bytes(std::string_view str) {
	std::vector<unsigned char>result;

	for (size_t i = 0; i < str.size(); i += 2)
		result.push_back((hexchar_to_int(str[i]) << 4) | hexchar_to_int(str[i + 1]));

	return result;
}

int main(void) {
	std::vector<unsigned char> expected{ 0xBA,0xAD,0xF0,0x0D,0x42 };
	assert(hexstr_to_bytes("BAADF00D42") == expected);
	assert(hexstr_to_bytes("BaaDf00d42") == expected);
}
*/

/*
// 25 문자열을 제목형식으로 변경

#include<string>
#include<cassert>
#include<vector>
#include<cassert>
template<class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template<class Elem>
using tstringstream = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template<class Elem>
tstring<Elem> capitalize(const tstring<Elem>& text) {
	tstringstream<Elem> result;
	bool newWord = true;

	for (const auto ch : text) {
		newWord = newWord || std::ispunct(ch) || std::isspace(ch);
		if (std::isalpha(ch)) {
			if (newWord) {
				result << static_cast<Elem>(std::toupper(ch));
				newWord = false;
			} else
				result << static_cast<Elem>(std::tolower(ch));
		} else
			result << ch;
	}
	return result.str();
}

int main(void) {
	using namespace std::string_literals;

	assert("The C++ Challenger"s == capitalize("the c== challenger"s));
	assert("This Is An Example, Should Work!"s == capitalize(L"THIS IS an Example, should wORK!"));
}
*/


/*
// 26 구획 문자로 나누어진 문자열 합치기

#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <assert.h>

template <typename Iter>
std::string join_strings(Iter begin, Iter end, char const* const separator) {
	std::ostringstream os;
	std::copy(begin, end - 1, std::ostream_iterator<std::string>(os, separator));
	os << *(end - 1);
	return os.str();
}


template <typename C>
std::string join_strings(C const& c, char const* const separator) {
	if (c.size() == 0) return std::string{};
	return join_strings(std::begin(c), std::end(c), separator);
}

int main() {
	using namespace std::string_literals;

	std::vector<std::string> v1{ "this","is","an","example" };
	std::vector<std::string> v2{ "example" };
	std::vector<std::string> v3{ };

	assert(join_strings(v1, " ") == "this is an example"s);

	assert(join_strings(v2, " ") == "example"s);

	assert(join_strings(v3, " ") == ""s);

	std::array<std::string, 4> a1{ {"this","is","an","example"} };
	std::array<std::string, 1> a2{ {"example"} };
	std::array<std::string, 0> a3{};

	assert(join_strings(a1, " ") == "this is an example"s);

	assert(join_strings(a2, " ") == "example"s);

	assert(join_strings(a3, " ") == ""s);
}
*/

/*
// 27 구획 문자 리스트를 바탕으로 문자열을 토큰으로 분리

#include <string>
#include <sstream>
#include <vector>
#include <assert.h>

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tstringstream = std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template<typename Elem>
inline std::vector<tstring<Elem>> split(tstring<Elem> text, const Elem delimiter) {
	auto sstr = tstringstream<Elem>{ text };
	auto tokens = std::vector<tstring<Elem>>{};
	auto token = tstring<Elem>{};
	while (std::getline(sstr, token, delimiter)) {
		if (!token.empty()) tokens.push_back(token);
	}

	return tokens;
}

template<typename Elem>
inline std::vector<tstring<Elem>> split(tstring<Elem> text, const tstring<Elem>& delimiters) {
	auto tokens = std::vector<tstring<Elem>>{};

	size_t pos, prev_pos = 0;
	while ((pos = text.find_first_of(delimiters, prev_pos)) != std::string::npos) {
		if (pos > prev_pos)
			tokens.push_back(text.substr(prev_pos, pos - prev_pos));
		prev_pos = pos + 1;
	}

	if (prev_pos < text.length())
		tokens.push_back(text.substr(prev_pos, std::string::npos));

	return tokens;
}

int main() {
	using namespace std::string_literals;

	std::vector<std::string> expected{ "this", "is", "a", "sample" };

	assert(expected == split("this is a sample"s, ' '));
	assert(expected == split("this,is a.sample!!"s, ",.! "s));
}
*/

/*
// 28 가장 긴 회문 부분 문자열 출력

#include<string>
#include<string_view>
#include<vector>
#include<assert.h>

std::string longest_palindrome(std::string_view str) {
	const size_t len = str.size();
	size_t longestBegin = 0;
	size_t maxLen = 1;

	std::vector<bool> table(len * len, false);

	for (size_t i = 0; i < len; i++)
		table[i * len + i] = true;

	for (size_t i = 0; i < len - 1; i++) {
		if (str[i] == str[i + 1]) {
			table[i * len + i + 1] = true;

			if (maxLen < 2) {
				longestBegin = i;
				maxLen = 2;
			}
		}
	}

	for (size_t k = 3; k <= len; k++) {
		for (size_t i = 0; i < len - k + 1; i++) {
			size_t j = i + k - 1;
			if (str[i] == str[j] && table[(i + 1) * len + j - 1]) {
				table[i * len + j] = true;
				if (maxLen < k) {
					longestBegin = i;
					maxLen = k;
				}
			}
		}
	}

	return std::string(str.substr(longestBegin, maxLen));
}

int main(void) {
	using namespace std::string_literals;

	assert(longest_palindrome("sahararahnide") == "hararah");
	assert(longest_palindrome("level") == "level");
	assert(longest_palindrome("s") == "s");
	assert(longest_palindrome("aabbcc") == "aa");
	assert(longest_palindrome("abab") == "aba");
}
*/

/*
// 29 차량 번호판 검증

#include <string>
#include <string_view>
#include <regex>
#include <assert.h>

bool validate_license_plate_format(std::string_view str) {
	std::regex rx(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
	return std::regex_match(str.data(), rx);
}

std::vector<std::string> extract_license_plate_numbers(std::string const& str) {
	std::regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
	std::smatch match;
	std::vector<std::string> results;

	for (auto i = std::sregex_iterator(std::cbegin(str), std::cend(str), rx);
		i != std::sregex_iterator(); ++i) {
		if ((*i)[1].matched)
			results.push_back(i->str());
	}

	return results;
}

int main() {
	assert(validate_license_plate_format("ABC-DE 123"));
	assert(validate_license_plate_format("ABC-DE 1234"));
	assert(!validate_license_plate_format("ABC-DE 12345"));
	assert(!validate_license_plate_format("abc-de 1234"));

	std::vector<std::string> expected{ "AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001" };
	std::string text("AAA-AA 123qwe-ty 1234  ABC-DE 123456..XYZ-WW 0001");
	assert(expected == extract_license_plate_numbers(text));
}
*/

/*
// 30 URL 추출하기

#include<string>
#include<string_view>
#include<regex>
#include<assert.h>

#ifdef USE_BOOST_OPTIONAL
#  include <boost/optional.hpp>
using boost::optional;
#else
#  include <optional>
using std::optional;
#endif

struct uri_parts {
	std::string protocol;
	std::string domain;
	optional<int> port;
	optional<std::string> path;
	optional<std::string> query;
	optional<std::string> fragment;
};

optional<uri_parts> parse_uri(std::string uri) {
	std::regex rx(R"(^(\w+):\/\/([\w.-]+)(:(\d+))?([\w\/\.]+)?(\?([\w=&]*)(#?(\w+))?)?$)");
	auto matches = std::smatch{};

	if (std::regex_match(uri, matches, rx)) {
		if (matches[1].matched && matches[2].matched) {
			uri_parts parts;
			parts.protocol = matches[1].str();
			parts.domain = matches[2].str();
			if (matches[4].matched) parts.port = std::stoi(matches[4]);
			if (matches[5].matched) parts.path = matches[5];
			if (matches[7].matched) parts.query = matches[7];
			if (matches[9].matched) parts.fragment = matches[9];

			return parts;
		}
	}
	return {};
}

int main(void) {
	auto p1 = parse_uri("https://packt.com");
	assert(p1);
	assert(p1->protocol == "https");
	assert(p1->domain == "packt.com");
	assert(!p1->port);
	assert(!p1->path);
	assert(!p1->query);
	assert(!p1->fragment);

	auto p2 = parse_uri("https://bbc.com:80/en/index.html?lite=true#ui");
	assert(p2);
	assert(p2->protocol == "https");
	assert(p2->domain == "bbc.com");
	assert(p2->port == 80);
	assert(p2->path.value() == "/en/index.html");
	assert(p2->query.value() == "lite=true");
	assert(p2->fragment.value() == "ui");

}
*/

/*
// 31 날짜를 문자열로 변환하기

#include<string>
#include<string_view>
#include<regex>
#include <assert.h>

std::string transform_date(std::string_view text) {
	auto rx = std::regex{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))" };
	return std::regex_replace(text.data(), rx, R"($5-$3-$1)");
}

int main(void) {
	using namespace std::string_literals;

	assert(
		transform_date("today is 01.12.2017!"s) ==
		"today is 2017-12-01!"s);
}
*/

/*
// 32 파스칼의 삼각형

#include <string>
#include <iostream>
#include <cmath>

unsigned int number_of_digits(unsigned const int i) {
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

void print_pascal_triangle(int const n) {
	for (int i = 0; i < n; i++) {
		auto x = 1;
		std::cout << std::string((n - i - 1) * (n / 2), ' ');
		for (int j = 0; j <= i; j++) {
			auto y = x;
			x = x * (i - j) / (j + 1);
			auto maxlen = number_of_digits(x) - 1;
			std::cout << y << std::string(n - 1 - maxlen - n % 2, ' ');
		}
		std::cout << std::endl;
	}
}

int main() {
	int n = 0;
	std::cout << "Levels (up to 10): ";
	std::cin >> n;
	if (n > 10)
		std::cout << "Value too large" << std::endl;
	else
		print_pascal_triangle(n);
}
*/

/*
// 33 프로세스를 표로 출력하기

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>

enum class procstatus{suspended,running};
std::string status_to_string(const procstatus status) {
	if (status == procstatus::suspended) return "suspended";
	else return "running";
}

enum class platforms {p32bit, p64bit};
std::string platform_to_string(const platforms platform) {
	if (platform == platforms::p32bit) return "32-bit";
	else return "64-bit";
}

struct procinfo {
	int id;
	std::string name;
	procstatus status;
	std::string account;
	size_t memory;
	platforms platform;
};

void print_processes(std::vector<procinfo> processes) {
	std::sort(std::begin(processes), std::end(processes), 
		[](const procinfo& p1, const procinfo& p2) {return p1.name < p2.name; });

	for (auto const& pi : processes) {
		std::cout << std::left << std::setw(25) << std::setfill(' ') << pi.name;
		std::cout << std::left << std::setw(8) << std::setfill(' ') << pi.id;
		std::cout << std::left << std::setw(12) << std::setfill(' ') << status_to_string(pi.status);
		std::cout << std::left << std::setw(15) << std::setfill(' ') << pi.account;
		std::cout << std::right << std::setw(10) << std::setfill(' ') << (int)(pi.memory / 1024);
		std::cout << std::left << ' ' << platform_to_string(pi.platform);
		std::cout << std::endl;
	}
}

int main(void) {
	using namespace std::string_literals;

	std::vector<procinfo> processes
	{
	   {512, "cmd.exe"s, procstatus::running, "SYSTEM"s, 148293, platforms::p64bit },
	   {1044, "chrome.exe"s, procstatus::running, "marius.bancila"s, 25180454, platforms::p32bit},
	   {7108, "explorer.exe"s, procstatus::running, "marius.bancila"s, 2952943, platforms::p64bit },
	   {10100, "chrome.exe"s, procstatus::running, "marius.bancila"s, 227756123, platforms::p32bit},
	   {22456, "skype.exe"s, procstatus::suspended, "marius.bancila"s, 16870123, platforms::p64bit },
	};

	print_processes(processes);
}
*/

/*
// 34 텍스트 파일에서 빈 줄 제거하기

#include<fstream>
#include<string>

#ifdef USE_BOOST_FILESYSTEM
#  include <boost/filesystem/path.hpp>
#  include <boost/filesystem/operations.hpp>
namespace fs = boost::filesystem;
#else
#  include <filesystem>
#  ifdef FILESYSTEM_EXPERIMENTAL
namespace fs = std::experimental::filesystem;
#  else
namespace fs = std::filesystem;
#  endif
#endif

void remove_empty_lines(fs::path filepath) {
	std::ifstream filein(filepath.native(), std::ios::in);
	if (!filein.is_open())
		throw std::runtime_error("cannot open input file");
	
	auto temppath = fs::temp_directory_path() / "temp.txt";
	std::ofstream fileout(temppath.native(), std::ios::out | std::ios::trunc);
	if (!fileout.is_open())
		throw std::runtime_error("cannot create temporay file");

	std::string line;
	while (std::getline(filein, line)) {
		if (line.length() > 0 && line.find_first_not_of(' ') != line.npos)
			fileout << line << '\n';
	}

	filein.close();
	fileout.close();

	fs::remove(filepath);
	fs::rename(temppath, filepath);
}

int main(void) {
	remove_empty_lines("sample34.txt");
}
*/

/*
// 35 디렉토리 크기 계산

#include<iostream>
#include<numeric>
#include<string>

#ifdef USE_BOOST_FILESYSTEM
#  include <boost/filesystem/path.hpp>
#  include <boost/filesystem/operations.hpp>
namespace fs = boost::filesystem;
#else
#  include <filesystem>
#  ifdef FILESYSTEM_EXPERIMENTAL
namespace fs = std::experimental::filesystem;
#  else
namespace fs = std::filesystem;
#  endif
#endif

std::uintmax_t get_directory_size(const fs::path& dir, const bool follow_symlinks = false) {
#ifdef USE_BOOST_FILESYSTEM
	auto iterator = fs::recursive_directory_iterator(
		dir,
		follow_symlinks ? fs::symlink_option::recurse : fs::symlink_option::none);
#else
	auto iterator = fs::recursive_directory_iterator(
		dir,
		follow_symlinks ? fs::directory_options::follow_directory_symlink : fs::directory_options::none);
#endif

	return std::accumulate(
		fs::begin(iterator), fs::end(iterator),0ull,
		[](const std::uintmax_t total,
			const fs::directory_entry& entry) {
				return total + (fs::is_regular_file(entry) ?
					fs::file_size(entry.path()) : 0);
		});
}

int main(void) {
	std::string path;
	std::cout << "Path: ";
	std::cin >> path;
	std::cout << "Size: " << get_directory_size(path) << std::endl;
}
*/

/*
// 36 주어진 날짜보다 오래된 파일 삭제

#include <iostream>
#include <chrono>

#ifdef USE_BOOST_FILESYSTEM
#  include <boost/filesystem/path.hpp>
#  include <boost/filesystem/operations.hpp>
namespace fs = boost::filesystem;
#else
#  include <filesystem>
#  ifdef FILESYSTEM_EXPERIMENTAL
namespace fs = std::experimental::filesystem;
#  else
namespace fs = std::filesystem;
#  endif
#endif

namespace ch = std::chrono;

template <typename Duration>
bool is_older_than(const fs::path& path, const Duration duration) {
	auto lastwrite = fs::last_write_time(path);
#ifdef USE_BOOST_FILESYSTEM
	auto ftimeduration = ch::system_clock::from_time_t(lastwrite).time_since_epoch();
#else
	auto ftimeduration = lastwrite.time_since_epoch();
#endif
	auto nowduration = (ch::system_clock::now() - duration).time_since_epoch();
	return ch::duration_cast<Duration>(nowduration - ftimeduration).count() > 0;
}

template <typename Duration>
void remove_files_older_than(const fs::path& path, const Duration duration) {
	try {
		if (fs::exists(path)) {
			if (is_older_than(path, duration)) {
				fs::remove(path);
			} else if (fs::is_directory(path)) {
				for (auto const& entry : fs::directory_iterator(path)) {
					remove_files_older_than(entry.path(), duration);
				}
			}
		}
	}
	catch (std::exception const& ex) {
		std::cerr << ex.what() << std::endl;
	}
}

int main() {
	using namespace std::chrono_literals;

#ifdef _WIN32
	auto path = R"(..\Test\)";
#else
	auto path = R"(../Test/)";
#endif

	remove_files_older_than(path, 1h + 20min);
}
*/

/*
// 37 디렉토리에서 정규 표현식과 일치하는 파일 찾기

#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <string_view>
#include <functional>

#ifdef USE_BOOST_FILESYSTEM
#  include <boost/filesystem/path.hpp>
#  include <boost/filesystem/operations.hpp>
namespace fs = boost::filesystem;
#else
#  include <filesystem>
#  ifdef FILESYSTEM_EXPERIMENTAL
namespace fs = std::experimental::filesystem;
#  else
namespace fs = std::filesystem;
#  endif
#endif

std::vector<fs::directory_entry> find_files(const fs::path& path, std::string_view regex) {
	std::vector<fs::directory_entry> result;
	std::regex rx(regex.data());

	std::copy_if(fs::recursive_directory_iterator(path),
		fs::recursive_directory_iterator(),
		std::back_inserter(result), [&rx](const fs::directory_entry& entry) {
			return fs::is_regular_file(entry.path()) && std::regex_match(entry.path().filename().string(), rx);
		});

	return result;
}

int main(void) {
	auto dir = fs::temp_directory_path();
	auto pattern = R"(wct[0-9a-zA-Z]{3}\.tmp)";
	auto result = find_files(dir, pattern);

	for (const auto& entry : result)
		std::cout << entry.path().string() << std::endl;
}
*/

/*
// 38 임시 로그 파일

#include <iostream>
#include <fstream>

#include "uuid.h"

#ifdef USE_BOOST_FILESYSTEM
#  include <boost/filesystem/path.hpp>
#  include <boost/filesystem/operations.hpp>
namespace fs = boost::filesystem;
#else
#  include <filesystem>
#  ifdef FILESYSTEM_EXPERIMENTAL
namespace fs = std::experimental::filesystem;
#  else
namespace fs = std::filesystem;
#  endif
#endif

class logger {
	fs::path       logpath;
	std::ofstream  logfile;
public:
	logger() {
		auto name = uuids::to_string(uuids::uuid_random_generator{}());
		logpath = fs::temp_directory_path() / (name + ".tmp");
		logfile.open(logpath.c_str(), std::ios::out | std::ios::trunc);
	}

	~logger() noexcept {
		try {
			if (logfile.is_open())
				logfile.close();
			if (!logpath.empty())
				fs::remove(logpath);
		}
		catch (...) {
		}
	}

	void persist(const fs::path& path) {
		logfile.close();
		fs::rename(logpath, path);
		logpath.clear();
	}

	logger& operator<<(std::string_view message) {
		logfile << message.data() << '\n';
		return *this;
	}
};

int main() {
	logger log;
	try {
		log << "this is a line" << "and this is another one";

		throw std::runtime_error("error");
	}
	catch (...) {
		log.persist(R"(lastlog.txt)");
	}
}
*/

/*
// 39 함수 실행 시간 측정

#include<iostream>
#include<chrono>
#include<thread>

template<typename Time = std::chrono::microseconds, 
	typename Clock = std::chrono::high_resolution_clock>
	struct perf_timer{
	template<typename F, typename... Args>
	static Time duration(F&& f, Args... args) {
		auto start = Clock::now();

		std::invoke(std::forward<F>(f), std::forward<Args>(args)...);

		auto end = Clock::now();

		return std::chrono::duration_cast<Time>(end - start);
	}
};

using namespace std::chrono_literals;

void f() {
	// simulate work
	std::this_thread::sleep_for(2s);
}

void g(const int a, const int b) {
	// simulate work
	std::this_thread::sleep_for(1s);
}

int main(void) {
	auto t1 = perf_timer<std::chrono::microseconds>::duration(f);
	auto t2 = perf_timer<std::chrono::milliseconds>::duration(g, 1, 2);

	auto total = std::chrono::duration<double, std::nano>(t1 + t2).count();

	std::cout << total << std::endl;
}
*/

/*
// 40 두 날짜 사이의 날 수를 반환
#include<iostream>
#include"date.h"

inline int number_of_days(
	const int y1, const unsigned int m1, const unsigned int d1,
	const int y2, const unsigned int m2, const unsigned int d2) 
{
	using namespace date;

	return (sys_days{ year{ y1 } / month{ m1 } / day{ d1 } } -
		sys_days{ year{ y2 } / month{ m2 } / day{ d2 } }).count();
}

inline int number_of_days(const date::sys_days& first, const date::sys_days& last) {
	return (last - first).count();
}

int main(void) {
	unsigned int y1 = 0, m1 = 0, d1 = 0;
	std::cout << "First date" << std::endl;
	std::cout << "Year:"; std::cin >> y1;
	std::cout << "Month:"; std::cin >> m1;
	std::cout << "Date:"; std::cin >> d1;

	std::cout << "Second date" << std::endl;
	unsigned int y2 = 0, m2 = 0, d2 = 0;
	std::cout << "Year:"; std::cin >> y2;
	std::cout << "Month:"; std::cin >> m2;
	std::cout << "Date:"; std::cin >> d2;

	std::cout << "Days between:" << number_of_days(y1, m1, d1, y2, m2, d2) << std::endl;

	using namespace date::literals;
	std::cout << "Days between:" << number_of_days(2018_y / jun / 1, 15_d / sep / 2018) << std::endl;
}
*/

/*
// 41 주어진 날짜의 요일 찾기
#include<iostream>
#include"date.h"
#include"iso_week.h"

unsigned int week_day(const int y, const unsigned int m, const unsigned int d) {
	using namespace date;

	if (m < 1 || m>12 || d < 1 || d>31) return 0;

	auto const dt = date::year_month_day{ year{ y }, month{ m }, day{ d } };
	auto const tiso = iso_week::year_weeknum_weekday{ dt };

	return (unsigned int)tiso.weekday();
}

int main(void) {
	int y = 0;
   unsigned int m = 0, d = 0;
   std::cout << "Year:"; std::cin >> y;
   std::cout << "Month:"; std::cin >> m;
   std::cout << "Day:"; std::cin >> d;

   std::cout << "Day of week:" << week_day(y, m, d) << std::endl;
}
*/

/*
// 42 한 해의 몇 번째 날인지 찾기

#include<iostream>
#include"date.h"
#include"iso_week.h"

unsigned int calendar_week(int const y, unsigned int const m, unsigned int const d) {
	using namespace date;

	if (m < 1 || m > 12 || d < 1 || d > 31) return 0;

	auto const dt = date::year_month_day{ year{ y }, month{ m }, day{ d } };
	auto const tiso = iso_week::year_weeknum_weekday{ dt };

	return (unsigned int)tiso.weeknum();
}

int day_of_year(int const y, unsigned int const m, unsigned int const d) {
	using namespace date;

	if (m < 1 || m > 12 || d < 1 || d > 31) return 0;

	return (sys_days{ year{ y } / month{ m } / day{ d } } -
		sys_days{ year{ y } / jan / 0 }).count();
}

int main() {
	int y = 0;
	unsigned int m = 0, d = 0;
	std::cout << "Year:"; std::cin >> y;
	std::cout << "Month:"; std::cin >> m;
	std::cout << "Day:"; std::cin >> d;

	std::cout << "Calendar week:" << calendar_week(y, m, d) << std::endl;
	std::cout << "Day of year:" << day_of_year(y, m, d) << std::endl;
}
*/

/*
// 43 여러 시간대에 걸친 회의 시작 출력
#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <iomanip>
#include "date.h"
#include "tz.h"

namespace ch = std::chrono;

struct user {
	std::string             Name;
	date::time_zone const* Zone;

	user(std::string_view name, std::string_view zone)
		: Name{ name.data() }, Zone(date::locate_zone(zone.data()))
	{
	}
};

template <class Duration, class TimeZonePtr>
void print_meeting_times(
	date::zoned_time<Duration, TimeZonePtr> const& time,
	std::vector<user> const& users) {
	std::cout
		<< std::left << std::setw(15) << std::setfill(' ')
		<< "Local time: "
		<< time << std::endl;

	for (auto const& user : users) {
		std::cout
			<< std::left << std::setw(15) << std::setfill(' ')
			<< user.Name
			<< date::zoned_time<Duration, TimeZonePtr>(user.Zone, time)
			<< std::endl;
	}
}

int main() {
	std::vector<user> users{
	   user{ "Ildiko", "Europe/Budapest" },
	   user{ "Jens", "Europe/Berlin" },
	   user{ "Jane", "America/New_York" }
	};

	unsigned int h, m;
	std::cout << "Hour:"; std::cin >> h;
	std::cout << "Minutes:"; std::cin >> m;

	date::year_month_day today = date::floor<date::days>(ch::system_clock::now());

	auto localtime = date::zoned_time<std::chrono::minutes>(
		date::current_zone(),
		static_cast<date::local_days>(today) + ch::hours{ h } + ch::minutes{ m });

	print_meeting_times(localtime, users);
}
*/

/*
// 44 달력 출력

#include <iostream>
#include <iomanip>
#include "date.h"
#include "iso_week.h"

unsigned int week_day(int const y, unsigned int const m, unsigned int const d) {
	using namespace date;

	if (m < 1 || m > 12 || d < 1 || d > 31) return 0;

	auto const dt = date::year_month_day{ year{ y }, month{ m }, day{ d } };
	auto const tiso = iso_week::year_weeknum_weekday{ dt };

	return (unsigned int)tiso.weekday();
}

void print_month_calendar(int const y, unsigned int m) {
	using namespace date;

	std::cout << "Mon Tue Wed Thu Fri Sat Sun" << std::endl;

	auto first_day_weekday = week_day(y, m, 1);
	auto last_day = (unsigned int)year_month_day_last(
		year{ y }, month_day_last{ month{ m } }).day();

	unsigned int index = 1;
	for (unsigned int day = 1; day < first_day_weekday; ++day, ++index) {
		std::cout << "    ";
	}

	for (unsigned int day = 1; day <= last_day; ++day) {
		std::cout
			<< std::right << std::setfill(' ') << std::setw(3)
			<< day << ' ';
		if (index++ % 7 == 0)
			std::cout << std::endl;
	}

	std::cout << std::endl;
}

int main() {
	unsigned int y = 0, m = 0;
	std::cout << "Year:"; std::cin >> y;
	std::cout << "Month:"; std::cin >> m;

	print_month_calendar(y, m);
}
*/

/*
// 45 우선순위 큐 
#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>

template<class T, class Compare = std::less<typename std::vector<T>::value_type>>
class priority_queue {
	typedef typename std::vector<T>::value_type value_type;
	typedef typename std::vector<T>::size_type size_type;
	typedef typename std::vector<T>::reference reference;
	typedef typename std::vector<T>::const_reference const_reference;
public:
	bool empty() const noexcept { return data.empty(); }
	size_type size() const noexcept { return data.size(); }

	void push(const value_type& value) {
		data.push_back(value);
		std::push_heap(std::begin(data), std::end(data), comparer);
	}

	void pop() {
		std::pop_heap(std::begin(data), std::end(data), comparer);
		data.pop_back();
	}

	const_reference top() const { return data.front(); }

	void swap(priority_queue& other) noexcept {
		swap(data, other.data);
		swap(comparer, other.comparer);
	}

private:
	std::vector<T> data;
	Compare comparer;
};

template<class T, class Compare>
void swap(priority_queue<T, Compare>& lhs,
	priority_queue<T, Compare>& rhs) noexcept(noexcept(lhs.swap(rhs))) 
{
	lhs.swap(rhs);
}

int main(void) {
	priority_queue<int> q;

	for (int i : {1, 5, 3, 1, 13, 21, 8})
		q.push(i);

	assert(!q.empty());
	assert(q.size() == 7);

	while (!q.empty()) {
		std::cout << q.top() << ' ';
		q.pop();
	}
}
*/

/*
// 46 원형 버퍼

#include<iostream>
#include<vector>
#include<assert.h>

template<class T>
class circular_buffer;

template<class T>
class circular_buffer_iterator {
	typedef circular_buffer_iterator self_type;
	typedef T value_type;
	typedef T& reference;
	typedef T const& const_reference;
	typedef T* pointer;
	typedef std::random_access_iterator_tag iterator_category;
	typedef ptrdiff_t difference_type;

public:
	circular_buffer_iterator(const circular_buffer<T>& buf, const size_t pos, const bool last):
		buffer_(buf),index_(pos),last_(last){ }

	self_type& operator++() {
		if (last_)
			throw std::out_of_range("Iterator cannot be incremented past the end of range.");
		index_ = (index_ + 1) % buffer_.data_.size();
		last_ = index_ == buffer_.next_pos();
		return *this;
	}

	self_type operator++(int) {
		self_type tmp = *this;
		++*this;
		return tmp;
	}

	bool operator==(const self_type& other) const {
		assert(compatible(other));
		return index_ == other.index_ && last_ == other.last_;
	}

	bool operator!=(const self_type& other) const {
		return!(*this == other);
	}

	const_reference operator*() const {
		return buffer_.data_[index_];
	}

	const_reference operator->() const {
		return buffer_.data_[index_];
	}
private:

	bool compatible(const self_type& other) const {
		return &buffer_ == &other.buffer_;
	}

	circular_buffer<T> const& buffer_;
	size_t index_;
	bool last_;
};

template<class T>
class circular_buffer {
	typedef circular_buffer_iterator<T> const_iterator;
	circular_buffer() = delete;
public:
	explicit circular_buffer(const size_t size) : data_(size){}
	bool clear() noexcept { head_ = -1; size_ = 0; }
	bool empty() const noexcept { return size_ == 0; }
	bool full() const noexcept { return size_ == data_.size(); }
	size_t capacity() const noexcept { return data_.size(); }
	size_t size() const noexcept { return size_; }

	void push(const T item) {
		head_ = next_pos();
		data_[head_] = item;
		if (size_ < data_.size()) size_++;
	}

	T pop() {
		if (empty()) throw std::runtime_error("empty buffer");

		auto pos = first_pos();
		size_--;
		return data_[pos];
	}

	const_iterator begin() const {
		return const_iterator(*this, first_pos(), empty());
	}

	const_iterator end() const {
		return const_iterator(*this, next_pos(), true);
	}
private:
	std::vector<T> data_;
	size_t head_ = -1;
	size_t size_ = 0;

	size_t next_pos() const noexcept { return size_ == 0 ? 0 : (head_ + 1) % data_.size(); }
	size_t first_pos() const noexcept { return size_ == 0 ? 0 : (head_ + data_.size() - size_ + 1) % data_.size(); }

	friend class circular_buffer_iterator<T>;
};

template<typename T>
void print(circular_buffer<T>& buf) {
	for (auto& e : buf)
		std::cout << e << ' ';

	std::cout << std::endl;
}

int main(void) {
	circular_buffer<int> cbuf(5);
	assert(cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 0);
	print(cbuf);

	cbuf.push(1);
	cbuf.push(2);
	cbuf.push(3);
	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 3);
	print(cbuf);

	auto item = cbuf.pop();
	assert(item == 1);
	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 2);

	cbuf.push(4);
	cbuf.push(5);
	cbuf.push(6);
	assert(!cbuf.empty());
	assert(cbuf.full());
	assert(cbuf.size() == 5);
	print(cbuf);

	cbuf.push(7);
	cbuf.push(8);
	assert(!cbuf.empty());
	assert(cbuf.full());
	assert(cbuf.size() == 5);
	print(cbuf);

	item = cbuf.pop();
	assert(item == 4);
	item = cbuf.pop();
	assert(item == 5);
	item = cbuf.pop();
	assert(item == 6);

	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 2);
	print(cbuf);

	item = cbuf.pop();
	assert(item == 7);
	item = cbuf.pop();
	assert(item == 8);

	assert(cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 0);
	print(cbuf);

	cbuf.push(9);
	assert(!cbuf.empty());
	assert(!cbuf.full());
	assert(cbuf.size() == 1);
	print(cbuf);
}
*/

/*
// 47 이중 버퍼

#include<vector>
#include<iostream>
#include<algorithm>
#include<thread>
#include<chrono>
#include<mutex>
#include<iterator>

template<typename T>
class double_buffer {
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* pointer;

public:
	explicit double_buffer(const size_t size):
		rdbuf(size), wrbuf(size){ }

	size_t size() const noexcept { return rdbuf.size(); }

	void write(const T* const ptr, const size_t size) {
		std::unique_lock<std::mutex> lock(mt);
		auto length = std::min(size, wrbuf.size());
		std::copy(ptr, ptr + length, std::begin(wrbuf));
		wrbuf.swap(rdbuf);
	}

	template<class Output>
	void read(Output it) const {
		std::unique_lock<std::mutex> lock(mt);
		std::copy(std::cbegin(rdbuf), std::cend(rdbuf), it);
	}

	pointer data() const {
		std::unique_lock(std::mutex) lock(mt);
		return rdbuf.data();
	}

	reference operator[](const size_t pos) {
		std::unique_lock<std::mutex> lock(mt);
		return rdbuf[pos];
	}

	const_reference operator[](const size_t pos) const {
		std::unique_lock<std::mutex> lock(mt);
		return rdbuf[pos];
	}

	void swap(double_buffer other) {
		std::swap(rdbuf, other.rdbuf);
		std::swap(wrbuf, other.wrbuf);
	}
private:
	std::vector<T> rdbuf;
	std::vector<T> wrbuf;
	mutable std::mutex mt;
};

template<typename T>
void print_buffer(const double_buffer<T>& buf) {
	buf.read(std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}

int main(void) {
	double_buffer<int> buf(10);

	std::thread t([&buf]() {
		for (int i = 1; i < 1000; i += 10) {
			int data[] = { i, i + 1, i + 2, i + 3, i + 4, i + 5, i + 6,i + 7,i + 8,i + 9 };
			buf.write(data, 10);

			using namespace std::chrono_literals;
			std::this_thread::sleep_for(100ms);
		}
	});

	auto start = std::chrono::system_clock::now();

	do {
		print_buffer(buf);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(150ms);
	} while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count() < 12);

	t.join();
}
*/

/*
// 48 범위 안에서 가장 빈번하게 등장하는 원소와 등장 횟수 반환

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

template<typename T>
std::vector<std::pair<T, size_t>> find_most_frequent(const std::vector<T>& range){
	std::map<T, size_t> counts;

	for (const auto& e : range) counts[e]++;

	auto maxelem = std::max_element(
		std::cbegin(counts), std::cend(counts),
		[](const auto& e1, const auto e2) {
			return e1.second < e2.second;
		});

	std::vector<std::pair<T, size_t>> result;

	std::copy_if(std::begin(counts), std::end(counts),
		std::back_inserter(result),
		[maxelem](const auto& kvp) {
			return kvp.second == maxelem->second;
		});

	return result;
}

int main(void) {
	auto range = std::vector<int>{ 1,1,3,5,8,13,3,5,8,8,5 };
	auto result = find_most_frequent(range);

	for (const auto& e : result)
		std::cout << e.first << " : " << e.second << std::endl;
}
*/

/*
// 49 텍스트 히스토그램

#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<iomanip>
#include<string>
#include<string_view>

std::map<char, double> analyze_text(std::string_view text) {

	std::map<char, double> frequencies;
	for (char ch = 'a'; ch <= 'z'; ch++) frequencies[ch] = 0;

	for (auto ch : text) {
		if (isalpha(ch))
			frequencies[ch]++;
	}
		
	auto total = std::accumulate(
		std::cbegin(frequencies), std::cend(frequencies),
		0ull, [](const auto sum, const auto& kvp) {
			return sum + static_cast<unsigned long long>(kvp.second);
		});

	std::for_each(
		std::begin(frequencies), std::end(frequencies),
		[total](auto& kvp) {
			kvp.second = (100.0 * kvp.second) / total;
		});

	return frequencies;
}

int main(void) {
	
	auto result = analyze_text(R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.)");

	for (const auto& kvp : result) {
		std::cout << kvp.first << " : " 
			<< std::fixed << std::setw(5) << std::setfill(' ') 
			<< std::setprecision(2) << kvp.second << std::endl;
	}
}
*/

/*
// 50 전화번호 목록 필터링

#include<string>
#include<string_view>
#include<vector>
#include<iostream>
#include<algorithm>

bool starts_with(std::string_view str, std::string_view prefix) {
	return str.find(prefix) == 0;
}

template<typename InputIt>
std::vector<std::string> filter_numbers(InputIt begin, InputIt end, const std::string& countryCode) {
	std::vector<std::string> result;

	std::copy_if(begin, end, std::back_inserter(result),
		[countryCode](const auto& number) {
			return starts_with(number, countryCode) || starts_with(number, "+" + countryCode);
		});

	return result;
}

std::vector<std::string> filter_numbers(const std::vector<std::string>& numbers, const std::string& countryCode) {
	return filter_numbers(std::begin(numbers), std::cend(numbers), countryCode);
}

int main(void) {
	std::vector<std::string> numbers{
	 "+40744909080",
	 "44 7520 112233",
	 "+44 7555 123456",
	 "40 7200 123456",
	 "7555 123456"
	};

	auto result = filter_numbers(numbers, "44");

	for (const auto& number : result)
		std::cout << number << std::endl;
}
*/

/*
// 51 전화번호 목록 변경

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

bool starts_with(std::string_view str, std::string_view prefix) {
	return str.find(prefix) == 0;
}

void normalize_phone_numbers(std::vector<std::string>& numbers, const std::string& countryCode) {
	std::transform(std::cbegin(numbers), std::cend(numbers), std::begin(numbers),
		[countryCode](const std::string& number) {
			std::string result;

			if (number.size() > 0) {
				if (number[0] == '0') result = "+" + countryCode + number.substr(1);
				else if (starts_with(number, countryCode)) result = "+" + number;
				else if (starts_with(number, countryCode)) result = number;
				else result = "+" +countryCode+ number;
			}

			result.erase(
				std::remove_if(
					std::begin(result), std::end(result),
					[](const char ch) {return isspace(ch); }),
				std::end(result));

			return result;
		});
}

int main() {
	std::vector<std::string> numbers{
	   "07555 123456",
	   "07555123456",
	   "+44 7555 123456",
	   "44 7555 123456",
	   "7555 123456"
	};

	normalize_phone_numbers(numbers, "44");

	for (auto const& number : numbers)
		std::cout << number << std::endl;
	
}
*/

/*
// 52 문자열로 만들 수 있는 모든 순열 생성

#include<iostream>
#include<string>
#include<algorithm>

void print_permutations(std::string str) {
	std::sort(std::begin(str), std::end(str));

	do {
		std::cout << str << std::endl;
	} while (std::next_permutation(std::begin(str), std::end(str)));
}

void next_permutation(std::string str, std::string perm) {
	if (str.empty()) std::cout << perm << std::endl;
	else {
		for (size_t i = 0; i < str.size(); ++i) {
			next_permutation(str.substr(1), perm + str[0]);

			std::rotate(std::begin(str), std::begin(str) + 1, std::end(str));
		}
	}
}

void print_permutations_recursive(std::string str) {
	next_permutation(str, "");
}

int main(void) {
	std::cout << "non-recursive version" << std::endl;
	print_permutations("main");

	std::cout << "recursive version" << std::endl;
	print_permutations_recursive("main");
}
*/

/*
// 53 영화 평균 계산 출력

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iomanip>

struct movie {
	int id;
	std::string title;
	std::vector<int> ratings;
};

double truncated_mean(std::vector<int> values, const double percentage) {
	std::sort(std::begin(values), std::end(values));

	auto remove_count = static_cast<size_t>(values.size() * percentage + 0.5);

	values.erase(std::begin(values), std::begin(values) + remove_count);
	values.erase(std::end(values) - remove_count, std::end(values));

	auto total = std::accumulate(
		std::cbegin(values), std::cend(values),
		0ull,
		[](const auto sum, const auto e) {
			return sum + e;
		});

	return static_cast<double>(total) / values.size();
}

void print_movie_ratings(const std::vector<movie>& movies) {
	for (const auto& m : movies) {
		std::cout
			<< m.title << " : "
			<< std::fixed << std::setprecision(1)
			<< truncated_mean(m.ratings, 0.05) << std::endl;
	}
}

int main(void) {
	std::vector<movie> movies
	{
	   { 101, "The Matrix",{ 10, 9, 10, 9, 9, 8, 7, 10, 5, 9, 9, 8 } },
	   { 102, "Gladiator",{ 10, 5, 7, 8, 9, 8, 9, 10, 10, 5, 9, 8, 10 } },
	   { 103, "Interstellar",{ 10, 10, 10, 9, 3, 8, 8, 9, 6, 4, 7, 10 } }
	};

	print_movie_ratings(movies);
}
*/

/*
// 54 쌍 알고리즘 함수

#include<iostream>
#include<vector>

template<typename Input, typename Output>
void pairwise(Input begin, Input end, Output result) {
	auto it = begin;
	while (it != end) {
		auto v1 = *it++; if (it == end) break;
		auto v2 = *it++;
		result++ = std::make_pair(v1, v2);
	}
}

template<typename T>
std::vector<std::pair<T, T>> pairwise(const std::vector<T>& range) {
	std::vector<std::pair<T, T>> result;
	pairwise(std::begin(range), std::end(range),std::back_inserter(result));

	return result;
}

int main(void) {
	std::vector<int> v{ 1, 1, 3, 5, 8, 13, 21 };

	auto result = pairwise(v);

	for (const auto& p : result)
		std::cout << '{' << p.first << ',' << p.second << '}' << std::endl;
}
*/

/*
// 55 결합 알고리즘 함수

#include<iostream>
#include<vector>

template<typename Input1, typename Input2, typename Output>
void zip(Input1 begin1, Input1 end1, Input2 begin2, Input2 end2, Output result) {
	auto it1 = begin1;
	auto it2 = begin2;
	while (it1 != end1 && it2 != end2)
		result++ = std::make_pair(*it1++, *it2++);
}

template <typename T, typename U>
std::vector<std::pair<T, U>> zip(const std::vector<T> & range1,const std::vector<U> & range2) {
	std::vector<std::pair<T, U>> result;

	zip(
		std::begin(range1), std::end(range1),
		std::begin(range2), std::end(range2),
		std::back_inserter(result));

	return result;
}

int main(void) {
	std::vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> v2{ 1, 1, 3, 5, 8, 13, 21 };

	auto result = zip(v1, v2);

	for (const auto& p : result)
		std::cout << '{' << p.first << ',' << p.second << '}' << std::endl;
	
}
*/

/*
// 56 선택 알고리즘 함수

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

template <
	typename T, typename A, typename F,
	typename R = typename std::decay<typename std::result_of<typename std::decay<F>::type& (typename std::vector<T, A>::const_reference)>::type>::type>
	const std::vector<R> select(std::vector<T, A>& c, F&& f) {
	
	std::vector<R> v;
	std::transform(std::cbegin(c), std::cend(c), std::back_inserter(v), std::forward<F>(f));
	
	return v;
}

struct book {
	int id;
	std::string title;
	std::string author;
};

int main(void) {
	std::vector<book> books{
	 {101, "The C++ Programming Language", "Bjarne Stroustrup"},
	 {203, "Effective Modern C++", "Scott Meyers"},
	 {404, "The Modern C++ Programming Cookbook", "Marius Bancila"} };

	auto titles = select(books, [](const book& b) {return b.title; });

	for (const auto& title : titles)
		std::cout << title << std::endl;
}
*/

/*
// 57 정렬 알고리즘 함수

#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <numeric>
#include <random>
#include <array>
#include <stack>
#include <chrono>
#include <assert.h>

template <class RandomIt>
RandomIt partition(RandomIt first, RandomIt last) {
	auto pivot = *first;
	auto i = first + 1;
	auto j = last - 1;
	while (i <= j) {
		while (i <= j && *i <= pivot) i++;
		while (i <= j && *j > pivot) j--;
		if (i < j) std::iter_swap(i, j);
	}

	std::iter_swap(i - 1, first);

	return i - 1;
}

template <class RandomIt, class Compare>
RandomIt partitionc(RandomIt first, RandomIt last, Compare comp) {
	auto pivot = *first;
	auto i = first + 1;
	auto j = last - 1;
	while (i <= j) {
		while (i <= j && comp(*i, pivot)) i++;
		while (i <= j && !comp(*j, pivot)) j--;
		if (i < j) std::iter_swap(i, j);
	}

	std::iter_swap(i - 1, first);

	return i - 1;
}

template <class RandomIt>
void quicksorti(RandomIt first, RandomIt last) {
	std::stack<std::pair<RandomIt, RandomIt>> st;
	st.push(std::make_pair(first, last));
	while (!st.empty()) {
		auto iters = st.top();
		st.pop();

		if (iters.second - iters.first < 2) continue;

		auto p = partition(iters.first, iters.second);

		st.push(std::make_pair(iters.first, p));
		st.push(std::make_pair(p + 1, iters.second));
	}
}

template <class RandomIt>
void quicksort(RandomIt first, RandomIt last) {
	if (first < last) {
		auto p = partition(first, last);
		quicksort(first, p);
		quicksort(p + 1, last);
	}
}

template <class RandomIt, class Compare>
void quicksort(RandomIt first, RandomIt last, Compare comp) {
	if (first < last) {
		auto p = partitionc(first, last, comp);
		quicksort(first, p, comp);
		quicksort(p + 1, last, comp);
	}
}

template <class RandomIt>
void print(RandomIt first, RandomIt last) {
	for (auto it = first; it < last; ++it) 
		std::cout << *it << ' ';
	std::cout << std::endl;
}

int main() {
	{
		std::vector<int> v{ 1, 5,3,8,6,2,9,7,4 };

		quicksort(std::begin(v), std::end(v));

		print(std::begin(v), std::end(v));
	}

	{
		std::array<int, 9> a{ 1,2,3,4,5,6,7,8,9 };

		quicksort(std::begin(a), std::end(a));

		print(std::begin(a), std::end(a));
	}


	{
		int a[]{ 9,8,7,6,5,4,3,2,1 };

		quicksort(std::begin(a), std::end(a));

		print(std::begin(a), std::end(a));
	}

	{
		std::vector<int> v{ 1,5,3,8,6,2,9,7,4 };

		quicksort(std::begin(v), std::end(v), std::greater_equal<>());

		print(std::begin(v), std::end(v));
	}

	{
		std::array<int, 9> a{ 1,2,3,4,5,6,7,8,9 };

		quicksort(std::begin(a), std::end(a), std::greater_equal<>());

		print(std::begin(a), std::end(a));
	}


	{
		int a[]{ 9,8,7,6,5,4,3,2,1 };

		quicksort(std::begin(a), std::end(a), std::greater_equal<>());

		print(std::begin(a), std::end(a));
	}

	{
		std::vector<int> v{ 1, 5,3,8,6,2,9,7,4 };

		quicksorti(std::begin(v), std::end(v));

		print(std::begin(v), std::end(v));
	}

	{
		const size_t count = 1000000;
		std::vector<int> data(count);

		std::random_device rd;
		std::mt19937 mt;
		auto seed_data = std::array<int, std::mt19937::state_size> {};
		std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
		std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
		mt.seed(seq);
		std::uniform_int_distribution<> ud(1, 1000);

		std::cout << "generating..." << std::endl;
		std::generate_n(std::begin(data), count, [&mt, &ud]() {return ud(mt); });

		auto d1 = data;
		auto d2 = data;

		std::cout << "sorting..." << std::endl;
		auto start1 = std::chrono::system_clock::now();
		quicksort(std::begin(d1), std::end(d1));
		auto end1 = std::chrono::system_clock::now();
		auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
		std::cout << "time: " << t1.count() << "ms" << std::endl;

		std::cout << "sorting..." << std::endl;
		auto start2 = std::chrono::system_clock::now();
		quicksorti(std::begin(d2), std::end(d2));
		auto end2 = std::chrono::system_clock::now();
		auto t2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
		std::cout << "time: " << t2.count() << "ms" << std::endl;

		assert(d1 == d2);
	}

}
*/

/*
// 58 노드 사이의 최단 경로 계산 (repeat)

#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<numeric>
#include<string>

template <typename Vertex = int, typename Weight=double>
class graph {
public:
	typedef Vertex vertex_type;
	typedef Weight weight_type;
	typedef std::pair<Vertex, Weight> neighbor_type;
	typedef std::vector<neighbor_type> neighbor_list_type;
public:
	void add_edge(const Vertex source, const Vertex target, const Weight weight, const bool bidirectional = true) {
		adjacency_list[source].push_back(std::make_pair(target, weight));
		adjacency_list[target].push_back(std::make_pair(source, weight));
	}

	size_t vertex_count() const { return adjacency_list.size(); }
	std::vector<Vertex> verteces() const {
		std::vector<Vertex> keys;
		for (const auto& kvp : adjacency_list)
			keys.push_back(kvp.first);
		return keys;
	}

	const neighbor_list_type& neighbors(const Vertex& v) const {
		auto pos = adjacency_list.find(v);
		if (pos == adjacency_list.end())
			throw std::runtime_error("vertex not found");

		return pos->second;
	}
	constexpr static Weight Infinity = std::numeric_limits<Weight>::infinity();
private:
	std::map<vertex_type, neighbor_list_type> adjacency_list;
};

template<typename Vertex, typename Weight>
void shortest_path(
	const graph<Vertex, Weight>& g,
	const Vertex source, 
	std::map<Vertex, Weight>& min_distance, 
	std::map<Vertex, Vertex>& previous) {

	const auto n = g.vertex_count();
	const auto verteces = g.verteces();

	min_distance.clear();
	for (const auto& v : verteces)
		min_distance[v] = graph<Vertex, Weight>::Infinity;
	min_distance[source] = 0;

	previous.clear();

	std::set<std::pair<Weight, Vertex>>vertex_queue;
	vertex_queue.insert(std::make_pair(min_distance[source], source));

	while (!vertex_queue.empty()) {
		auto dist = vertex_queue.begin()->first;
		auto u = vertex_queue.begin()->second;

		vertex_queue.erase(std::begin(vertex_queue));

		const auto& neighbors = g.neighbors(u);
		for (const auto& neighbor : neighbors) {
			auto v = neighbor.first;
			auto w = neighbor.second;
			auto dist_via_u = dist + w;
			if (dist_via_u < min_distance[v]) {
				vertex_queue.erase(std::make_pair(min_distance[v], v));

				min_distance[v] = dist_via_u;
				previous[v] = u;
				vertex_queue.insert(std::make_pair(min_distance[v], v));
			}
		}
	}
}

template<typename Vertex>
void build_path(const std::map<Vertex, Vertex>& prev, const Vertex v, std::vector<Vertex>& result) {
	result.push_back(v);

	auto pos = prev.find(v);
	if (pos == std::end(prev))return;

	build_path(prev, pos->second, result);
}

template <typename Vertex>
std::vector<Vertex> build_path(const std::map<Vertex, Vertex> & prev, Vertex const v) {
	std::vector<Vertex> result;
	build_path(prev, v, result);
	std::reverse(std::begin(result), std::end(result));
	return result;
}

template <typename Vertex>
void print_path(const std::vector<Vertex>& path) {
	for (size_t i = 0; i < path.size(); ++i) {
		std::cout << path[i];
		if (i < path.size() - 1)
			std::cout << " -> ";
	}
}

graph<char, double> make_graph() {
	graph<char, double> g;
	g.add_edge('A', 'B', 4);
	g.add_edge('A', 'H', 8);
	g.add_edge('B', 'C', 8);
	g.add_edge('B', 'H', 11);
	g.add_edge('C', 'D', 7);
	g.add_edge('C', 'F', 4);
	g.add_edge('C', 'J', 2);
	g.add_edge('D', 'E', 9);
	g.add_edge('D', 'F', 14);
	g.add_edge('E', 'F', 10);
	g.add_edge('F', 'G', 2);
	g.add_edge('G', 'J', 6);
	g.add_edge('G', 'H', 1);
	g.add_edge('H', 'J', 7);

	return g;
}

graph<char, double> make_graph_wiki() {
	graph<char, double> g;
	g.add_edge('A', 'B', 7);
	g.add_edge('A', 'C', 9);
	g.add_edge('A', 'F', 14);
	g.add_edge('B', 'C', 10);
	g.add_edge('B', 'D', 15);
	g.add_edge('C', 'D', 11);
	g.add_edge('C', 'F', 2);
	g.add_edge('D', 'E', 6);
	g.add_edge('E', 'F', 9);

	return g;
}

graph<std::string, double> make_graph_map() {
	graph<std::string, double> g;

	g.add_edge("London", "Reading", 41);
	g.add_edge("London", "Oxford", 57);
	g.add_edge("Reading", "Swindon", 40);
	g.add_edge("Swindon", "Bristol", 40);
	g.add_edge("Oxford", "Swindon", 30);
	g.add_edge("London", "Southampton", 80);
	g.add_edge("Southampton", "Bournemouth", 33);
	g.add_edge("Bournemouth", "Exeter", 89);
	g.add_edge("Bristol", "Exeter", 83);
	g.add_edge("Bristol", "Bath", 12);
	g.add_edge("Swindon", "Bath", 35);
	g.add_edge("Reading", "Southampton", 50);

	return g;
}

int main() {
	{
		auto g = make_graph();

		char source = 'A';
		std::map<char, double>  min_distance;
		std::map<char, char> previous;
		shortest_path(g, source, min_distance, previous);

		for (auto const& kvp : min_distance) {
			std::cout << source << " -> " << kvp.first << " : "
				<< kvp.second << '\t';

			print_path(build_path(previous, kvp.first));

			std::cout << std::endl;
		}
	}

	{
		auto g = make_graph_wiki();

		char source = 'A';
		std::map<char, double>  min_distance;
		std::map<char, char> previous;
		shortest_path(g, source, min_distance, previous);

		for (auto const& kvp : min_distance) {
			std::cout << source << " -> " << kvp.first << " : "
				<< kvp.second << '\t';

			print_path(build_path(previous, kvp.first));

			std::cout << std::endl;
		}
	}

	{
		auto g = make_graph_map();

		std::string source = "London";
		std::map<std::string, double>  min_distance;
		std::map<std::string, std::string> previous;
		shortest_path(g, source, min_distance, previous);

		for (auto const& kvp : min_distance) {
			std::cout << source << " -> " << kvp.first << " : "
				<< kvp.second << '\t';

			print_path(build_path(previous, kvp.first));

			std::cout << std::endl;
		}
	}
}
*/

/*
// 59 족제비 프로그램

#include<iostream>
#include<string>
#include<sstream>
#include<string_view>
#include<random>
#include<algorithm>
#include<array>
#include<iomanip>

class weasel {
	std::string target;
	std::uniform_int_distribution<> chardist;
	std::uniform_real_distribution<> ratedist;
	std::mt19937 mt;
	std::string const allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

public:
	weasel(std::string_view t) :
		target(t), chardist(0, 26), ratedist(0, 100) {
		std::random_device rd;
		auto seed_data = std::array<int, std::mt19937::state_size>{};
		std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
		std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
		mt.seed(seq);
	}

	void run(const int copies) {
		auto parent = make_random();
		int step = 1;
		std::cout << std::left << std::setw(5) << std::setfill(' ') << step << parent << std::endl;

		do {
			std::vector<std::string> children;
			std::generate_n(
				std::back_inserter(children),
				copies,
				[parent, this]() {return mutate(parent, 5); });

			parent = *std::max_element(std::begin(children), std::end(children),
				[this](std::string_view c1, std::string_view c2) {return fitness(c1) < fitness(c2); });

			std::cout << std::setw(5) << std::setfill(' ') << step << parent << std::endl;
			step++;
		} while (parent != target);
	}

private:
	weasel() = delete;

	double fitness(std::string_view candidate) {
		int score = 0;
		for (size_t i = 0; i < candidate.size(); ++i) {
			if (candidate[i] == target[i])
				score++;
		}

		return score;
	}

	std::string mutate(std::string_view parent, const double rate) {
		std::stringstream sstr;
		for (const auto c : parent) {
			auto nc = ratedist(mt) > rate ? c : allowed_chars[chardist(mt)];
			sstr << nc;
		}

		return sstr.str();
	}

	std::string make_random() {
		std::stringstream sstr;
		for (size_t i = 0; i < target.size(); ++i)
			sstr << allowed_chars[chardist(mt)];

		return sstr.str();
	}
};

int main(void) {
	weasel w("METHINKS IT IS LIKE A WEASEL");
	w.run(100);
}
*/

// 60 생명 게임

#include<iostream>
#include<vector>
#include<random>
#include<array>
#include<thread>
#include<chrono>

class universe {
private:
	universe() = delete;

public:
	enum class seed{
		random,
		ten_cell_row,
		small_explorer,
		explorer
	};

public:
	universe(const size_t width, const size_t height) :
		rows(height), columns(width), grid(width* height), dist(0, 4) {
		std::random_device rd;
		auto seed_data = std::array<int, std::mt19937::state_size>{};
		std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
		std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
		mt.seed(seq);
	}

	void run(const seed s, 
		const int generations, 
		const std::chrono::microseconds ms = std::chrono::milliseconds(100)) {
		reset();
		initialize(s);
		display();

		int i = 0;
		do {
			next_generation();
			display();

			using namespace std::chrono_literals;
			std::this_thread::sleep_for(ms);
		} while (i++ < generations || generations == 0);
	}

private:
	void next_generation() {
		std::vector<unsigned char> newgrid(grid.size());

		for (size_t r = 0; r < rows; ++r) {
			for (size_t c = 0; c < columns; ++c) {
				auto count = count_neighbors(r, c);

				if (cell(c, r) == alive) newgrid[r * columns + c] = (count == 2 || count == 3) ? alive : dead;
				else newgrid[r * columns + c] = (count == 3) ? alive : dead;
			}
		}
		grid.swap(newgrid);
	}

	void reset_display() {
#ifdef _WIN32
		system("cls");
#endif
	}

	void display() {
		reset_display();

		for (size_t r = 0; r < rows; ++r) {
			for (size_t c = 0; c < columns; ++c) {
				std::cout << (cell(c, r) ? '*' : ' ');
			}
			std::cout << std::endl;
		}
	}

	void initialize(seed const s) {
		if (s == seed::small_explorer) {
			auto mr = rows / 2;
			auto mc = columns / 2;

			cell(mc, mr) = alive;
			cell(mc - 1, mr + 1) = alive;
			cell(mc, mr + 1) = alive;
			cell(mc + 1, mr + 1) = alive;
			cell(mc - 1, mr + 2) = alive;
			cell(mc + 1, mr + 2) = alive;
			cell(mc, mr + 3) = alive;
		} else if (s == seed::explorer) {
			auto mr = rows / 2;
			auto mc = columns / 2;

			cell(mc - 2, mr - 2) = alive;
			cell(mc, mr - 2) = alive;
			cell(mc + 2, mr - 2) = alive;

			cell(mc - 2, mr - 1) = alive;
			cell(mc + 2, mr - 1) = alive;
			cell(mc - 2, mr) = alive;
			cell(mc + 2, mr) = alive;
			cell(mc - 2, mr + 1) = alive;
			cell(mc + 2, mr + 1) = alive;

			cell(mc - 2, mr + 2) = alive;
			cell(mc, mr - 2) = alive;
			cell(mc + 2, mr + 2) = alive;
		} else if (s == seed::ten_cell_row) {
			for (size_t c = columns / 2 - 5; c < columns / 2 + 5; c++)
				cell(c, rows / 2) = alive;
		} else {
			for (size_t r = 0; r < rows; ++r) {
				for (size_t c = 0; c < columns; ++c) {
					cell(c, r) = dist(mt) == 0 ? alive : dead;
				}
			}
		}
	}

	void reset() {
		for (size_t r = 0; r < rows; ++r) {
			for (size_t c = 0; c < columns; ++c) {
				cell(c, r) = dead;
			}
		}
	}


	int count_alive() { return 0; }

	template<typename T1, typename... T>
	auto count_alive(T1 s, T... ts) { return s + count_alive(ts...); }

	int count_neighbors(size_t const row, size_t const col) {
		if (row == 0 && col == 0)
			return count_alive(cell(1, 0), cell(1, 1), cell(0, 1));
		if (row == 0 && col == columns - 1)
			return count_alive(cell(columns - 2, 0), cell(columns - 2, 1), cell(columns - 1, 1));
		if (row == rows - 1 && col == 0)
			return count_alive(cell(0, rows - 2), cell(1, rows - 2), cell(1, rows - 1));
		if (row == rows - 1 && col == columns - 1)
			return count_alive(cell(columns - 1, rows - 2), cell(columns - 2, rows - 2), cell(columns - 2, rows - 1));
		if (row == 0 && col > 0 && col < columns - 1)
			return count_alive(cell(col - 1, 0), cell(col - 1, 1), cell(col, 1), cell(col + 1, 1), cell(col + 1, 0));
		if (row == rows - 1 && col > 0 && col < columns - 1)
			return count_alive(cell(col - 1, row), cell(col - 1, row - 1), cell(col, row - 1), cell(col + 1, row - 1), cell(col + 1, row));
		if (col == 0 && row > 0 && row < rows - 1)
			return count_alive(cell(0, row - 1), cell(1, row - 1), cell(1, row), cell(1, row + 1), cell(0, row + 1));
		if (col == columns - 1 && row > 0 && row < rows - 1)
			return count_alive(cell(col, row - 1), cell(col - 1, row - 1), cell(col - 1, row), cell(col - 1, row + 1), cell(col, row + 1));

		return count_alive(cell(col - 1, row - 1), cell(col, row - 1), cell(col + 1, row - 1), cell(col + 1, row), cell(col + 1, row + 1), cell(col, row + 1), cell(col - 1, row + 1), cell(col - 1, row));
	}

	unsigned char& cell(size_t const col, size_t const row) {
		return grid[row * columns + col];
	}
private:
	size_t rows;
	size_t columns;

	std::vector<unsigned char> grid;
	const unsigned char alive = 1;
	const unsigned char dead = 0;

	std::uniform_int_distribution<> dist;
	std::mt19937 mt;
};

int main() {
	using namespace std::chrono_literals;

	universe u(50, 20);
	u.run(universe::seed::random, 100, 100ms);
}
