

#ifndef MPBLIB_HPP
#define MPBLIB_HPP

#include <boost/date_time/gregorian/gregorian.hpp>

typedef boost::gregorian::date date_t;

namespace mpbns
{
	
	class MPBClass
	{
		public:
		MPBClass(const date_t& mydate);
		date_t get_date() const;
		private:
		date_t date_;
	};
	
}

#endif
