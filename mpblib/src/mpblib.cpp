
#include "mpblib.hpp"

mpbns::MPBClass::MPBClass(const date_t& mydate) : date_(mydate)
{
}

date_t mpbns::MPBClass::get_date() const
{
	return this->date_;
}
