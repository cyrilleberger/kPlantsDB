#include "Order.h"

#include <QString>

#include "DatabaseConnection.h"
#include "QueryResult.h"

using namespace kPlantsDB;

struct Order::Private : public QSharedData
{
  DatabaseConnection* connection;
  QString entityId;
  mutable QString name;
};

Order::Order(const QString& _entityId, DatabaseConnection* _connection) : d(new Private)
{
  d->connection = _connection;
  d->entityId   = _entityId;
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

QString Order::name() const
{
  if(d->name.isEmpty())
  {
    QString q = QString("select distinct ?z where { <%1> rdfs:label ?z FILTER (lang(?z) = 'en') } LIMIT 1").arg(d->entityId);

    QueryResult qr = d->connection->execute(q);
    if(qr.lines().size() == 1)
    {
      d->name = qr.lines()[0]["z"].toMap()["value"].toString();
    }
  }
  return d->name;
}

