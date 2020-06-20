using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace CarDealer.Models
{
    public class DatabaseInitializer : DropCreateDatabaseIfModelChanges<SiteContext>
    {
        protected override void Seed(SiteContext context)
        {
            var sites = new List<Site>()
            {
                new Site {SiteName = "First In The Row", ZipCode = 4030, Address = "Debrecen, Böszörméyni út 13.", ParkinglotNum = 90},
                new Site {SiteName = "Second In The Row", ZipCode = 1019, Address = "Budapest, Andrássy út 23.", ParkinglotNum = 150},
                new Site {SiteName = "Third In The Row", ZipCode = 4400, Address = "Nyíregyháza, Debreceni út 7.", ParkinglotNum = 65},
                new Site {SiteName = "Fourth In The Row", ZipCode = 6700, Address = "Szeged, Kálvária sugárút 81.", ParkinglotNum = 130},
            };
            sites.ForEach(s => context.Sites.Add(s));
            context.SaveChanges();

            //var cars = new List<Car>()
            //{
            //    new Car {Brand="Lada", Type="Niva 1700", AgeGroup = 18, DoM = DateTime.Parse("2000-01-01"), Condition="good condition", NoO = 4, SiteID = 1},
            //    new Car {Brand="Opel", Type="Vectra B", AgeGroup = 22, DoM = DateTime.Parse("1996-01-01"), Condition="used", NoO = 2, SiteID = 1},
            //    new Car {Brand="Suzuki", Type="Swift GC", AgeGroup = 20, DoM = DateTime.Parse("1998-01-01"), Condition="used", NoO = 1, SiteID = 2},
            //    new Car {Brand="Fiat", Type="Punto", AgeGroup = 19, DoM = DateTime.Parse("1999-01-01"), Condition="good condition", NoO = 3, SiteID = 2},
            //    new Car {Brand="Ford", Type="Focus", AgeGroup = 18, DoM = DateTime.Parse("2000-01-01"), Condition="shattered", NoO = 2, SiteID = 3},
            //    new Car {Brand="Opel", Type="Corsa C Club", AgeGroup = 15, DoM = DateTime.Parse("2003-01-01"), Condition="good condition", NoO = 3, SiteID = 3},
            //    new Car {Brand="Mini", Type="Cooper", AgeGroup = 1, DoM = DateTime.Parse("2017-01-01"), Condition="new", NoO = 0, SiteID = 4}
            //};
            //cars.ForEach(s => context.Cars.Add(s));
            //context.SaveChanges();
        }
    }
}