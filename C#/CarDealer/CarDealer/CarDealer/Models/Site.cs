using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace CarDealer.Models
{
    public class Site
    {
        [Key]
        public int SiteID { get; set; }
        [Required(ErrorMessage = "Name of the Site is required!")]
        public string SiteName { get; set; }
        [Required(ErrorMessage = "Zip Code is required!")]
        [Range(1000,9999, ErrorMessage = "Zip Code must be between 1000 and 9999")]
        public int ZipCode { get; set; }
        [Required(ErrorMessage = "Address is required!")]
        public string Address { get; set; }
        [Required(ErrorMessage = "Number of parkinglots is required!")]
        public int ParkinglotNum { get; set; }

        public virtual ICollection<Car> Cars { get; set; }
    }
}