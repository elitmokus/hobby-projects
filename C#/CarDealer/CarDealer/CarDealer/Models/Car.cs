using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace CarDealer.Models
{
    public class Car
    {
        [Key]
        public int CarID { get; set; }
        [Required(ErrorMessage = "Brand of the car is required!")]
        public string Brand { get; set; }
        [Required(ErrorMessage = "Type of the car is required!")]
        public string Type { get; set; }
        public int AgeGroup { get; set; }
        [DataType(DataType.Date)]
        [DisplayFormat(DataFormatString = "{0:yyyy}", ApplyFormatInEditMode = true)]
        public DateTime DoM{ get; set; } // Date of Manufacture
        public string Condition { get; set; }
        public int NoO { get; set; } // Number of Owners

        public int SiteID { get; set; }

        public virtual Site Site { get; set; }
    }
}