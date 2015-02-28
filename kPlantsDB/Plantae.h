#include <QList>

namespace kPlantsDB
{
  class Order;
  class Plantae
  {
  public:
    Plantae();
    ~Plantae();
    QList<Order> orders() const;
  private:
    struct Private;
    Private* const d;
  };
}