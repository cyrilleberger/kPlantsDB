#include "Plantae.h"

using namespace kPlantsDB;

struct Plantae::Private
{
  
};

Plantae::Plantae() : d(new Private)
{

}

Plantae::~Plantae()
{

}

QList< Order > Plantae::orders() const
{

"select distinct ?y where {"
"?x <http://dbpedia.org/property/regnum> \"Plantae\"@en ."
"?x dbpedia-owl:order ?y"
"} LIMIT 100";

  
}
