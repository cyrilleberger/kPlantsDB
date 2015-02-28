#include "Order.h"

#include <QString>

using namespace kPlantsDB;

struct Order::Private : public QSharedData
{
  QString entityId;
};

Order::Order(const QString& _entityId) : d(new Private)
{
  d->entityId = _entityId;
}

Order::Order(const Order& _other) : d(_other.d)
{

}

Order& Order::operator=(const Order& _other)
{
  d = _other.d;
  return *this;
}

Order::~Order()
{

}
