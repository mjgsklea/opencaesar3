// This file is part of openCaesar3.
//
// openCaesar3 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// openCaesar3 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with openCaesar3.  If not, see <http://www.gnu.org/licenses/>.

#include "oc3_goodorders.hpp"
#include "oc3_foreach.hpp"
#include <map>

class GoodOrders::Impl
{
public:
  typedef std::map< Good::Type, Order > Orders;
  Orders orders;
};

GoodOrders::~GoodOrders()
{

}

GoodOrders::GoodOrders() : _d( new Impl )
{

}

void GoodOrders::set( Order rule )
{
  foreach( Impl::Orders::value_type& item, _d->orders )
  {
    if( item.second != GoodOrders::none )
    {
      item.second = rule;
    }
  }
}

void GoodOrders::set(const Good::Type type, Order rule )
{
  _d->orders[ type ] = rule;  
}

GoodOrders::Order GoodOrders::get( const Good::Type type )
{
  Impl::Orders::iterator it = _d->orders.find( type );
  return it != _d->orders.end() ? (*it).second : GoodOrders::none;
}
