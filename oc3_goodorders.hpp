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

#ifndef __OPENCAESAR3_GOODORDERS_H_INCLUDED__
#define __OPENCAESAR3_GOODORDERS_H_INCLUDED__

#include "oc3_good.hpp"
#include "oc3_scopedptr.hpp"

class GoodOrders 
{
public:
  typedef enum { accept=0, reject, deliver, none } Order;
  
  GoodOrders();
  ~GoodOrders();

  void set( const Good::Type type, Order rule );
  void set( Order rule );
  Order get( const Good::Type type );

private:
  class Impl;
  ScopedPtr< Impl > _d;
};

#endif //__OPENCAESAR3_GOODORDERS_H_INCLUDED__
