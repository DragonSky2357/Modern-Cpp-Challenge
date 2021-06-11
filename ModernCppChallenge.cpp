

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
