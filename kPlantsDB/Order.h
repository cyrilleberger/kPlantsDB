#include <QSharedDataPointer>

namespace kPlantsDB
{
  class Order
  {
  public:
    Order(const QString& _entityId);
    Order(const Order& _other);
    Order& operator=(const Order& _other);
    ~Order();
  private:
    struct Private;
    QSharedDataPointer<Private> d;
  };
}
