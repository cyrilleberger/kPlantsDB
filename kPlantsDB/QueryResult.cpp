#include "QueryResult.h"

using namespace kPlantsDB;

struct QueryResult::Private : public QSharedData
{
  QList< QueryResult::Line > lines;
};

QueryResult::QueryResult(const QList< QueryResult::Line >& _lines) : d(new Private)
{
  d->lines = _lines;
}

QueryResult::QueryResult(const QueryResult& _other) : d(_other.d)
{

}

QueryResult& QueryResult::operator=(const QueryResult& _other)
{
  d = _other.d;
  return *this;
}

QueryResult::~QueryResult()
{
}

QList< QueryResult::Line > QueryResult::lines() const
{
  return d->lines;
}

#include <QDebug>

QDebug& operator<<(QDebug d, QueryResult t)
{
  d << t.lines();
}
