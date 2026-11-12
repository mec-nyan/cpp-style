// example.cpp
//
// Example C++ program in "one big file" to try the different formatting options.
//
// BEWARE!
//
// These are not meant to be REAL programming examples!  The code here is just to visualise the
// resulting formatted code.
//
// ---

#include <format>
#include <print>
#include <unordered_map>
#include <vector>


using namespace std::literals;

// Namespaces and definitions (usually on a header file):
namespace mazs
{
	auto add_stuff( int a, int b ) -> int;

	auto accumulate_numeric( const std::vector<int>& v ) -> double;

	enum class Quadrant
	{
		centre,
		south,
		west,
		north,
		east,
		south_east,
		south_west,
		north_east,
		north_west,
	};

	// TODO: Just for fun, implement formatter for Quadrant.
	std::unordered_map<Quadrant, std::string> cardinal_points{
		{ Quadrant::centre, "Centre" },
		{ Quadrant::south, "South" },
		{ Quadrant::west, "West" },
		{ Quadrant::north, "North" },
		{ Quadrant::east, "East" },
		{ Quadrant::south_east, "South east" },
		{ Quadrant::south_west, "South west" },
		{ Quadrant::north_east, "North east" },
		{ Quadrant::north_west, "North west" },
	};

	class Point
	{
	public:
		Point()
		{
		}

		Point( int x, int y ) : _x{ x }, _y{ y }
		{
		}

		~Point()
		{
		}

		auto x() const -> int;
		auto y() const -> int;

		auto move( int x, int y ) -> Point&;
		auto move_x( int x ) -> Point&;
		auto move_y( int y ) -> Point&;
		auto center() -> Point&;

		auto where_am_i() -> Quadrant;

	private:
		int _x{ 0 };
		int _y{ 0 };
	};

}  // namespace mazs


auto run() -> int;


auto main( int argc, char* argv[] ) -> int
{
	return run();
}


// Namespaces and declarations (usually on an implementation file):
namespace mazs
{
	auto add_stuff( int a, int b ) -> int
	{
		return a + b;
	}

	auto accumulate_numeric( const std::vector<int>& v ) -> double
	{
		double result{ 0 };

		for ( auto& n : v )
		{
			result += n;
		}

		return result;
	}

	auto Point::x() const -> int
	{
		return _x;
	}

	auto Point::y() const -> int
	{
		return _y;
	}

	auto Point::move( int x, int y ) -> Point&
	{
		_x = x;
		_y = y;

		return *this;
	}

	auto Point::move_x( int x ) -> Point&
	{
		_x = x;

		return *this;
	}

	auto Point::move_y( int y ) -> Point&
	{
		_y = y;

		return *this;
	}

	auto Point::center() -> Point&
	{
		_x = 0;
		_y = 0;

		return *this;
	}

	auto Point::where_am_i() -> Quadrant
	{
		if ( _x > 0 )
		{
			if ( _y > 0 )
			{
				return Quadrant::north_east;
			}
			else if ( _y < 0 )
			{
				return Quadrant::south_east;
			}
			else
			{
				return Quadrant::east;
			}
		}
		else if ( _x < 0 )
		{
			if ( _y > 0 )
			{
				return Quadrant::north_west;
			}
			else if ( _y < 0 )
			{
				return Quadrant::south_west;
			}
			else
			{
				return Quadrant::west;
			}
		}
		else
		{
			if ( _y > 0 )
			{
				return Quadrant::north;
			}
			else if ( _y < 0 )
			{
				return Quadrant::south;
			}
		}
		return Quadrant::centre;
	}
}  // namespace mazs


auto run() -> int
{
	auto message{ "アニメはすき！"s };

	std::println( "{}", message );

	auto a{ 40 };
	auto b{ 2 };

	std::println( "The answer is {}", mazs::add_stuff( a, b ) );

	std::vector v{ 1, 1, 2, 3, 5, 8 };
	auto        result{ mazs::accumulate_numeric( v ) };

	std::println( "The sum of the vector elements is {}.", result );

	mazs::Point p{ a, b };

	std::println( "I'm a point at {}, {}.", p.x(), p.y() );
	std::println( "\tThat's {} btw.", mazs::cardinal_points.at( p.where_am_i() ) );

	return 0;
}
