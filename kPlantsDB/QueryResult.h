#include <QHash>
#include <QVariant>
#include <QSharedDataPointer>

namespace kPlantsDB
{
  class QueryResult
  {
  public:
    typedef QHash<QString, QVariant> Line;
  public:
    QueryResult(const QList<Line>& _lines );
    QueryResult(const QueryResult& _other);
    QueryResult& operator=(const QueryResult& _other);
    ~QueryResult();
    QList<Line> lines() const;
  private:
    struct Private;
    QSharedDataPointer<Private> d;
  };
}

QDebug &operator<<(QDebug d, kPlantsDB::QueryResult t);
