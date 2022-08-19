using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace Pizzatorium.Models
{
    public class Design
    {
        public Design (eIngredient _ingredient,eArea _area, ePayment _payment,
            eSize _size, decimal _cost, string _deliveryPersonnel, bool _complete,string Address)
        {
            this.ingredient = _ingredient;
            this.cost = _cost;
            this.size = _size;
            this.complete = _complete;
            this.payment = _payment;
            this.area = _area;
            this.deliveryPersonnel = _deliveryPersonnel;
            this.Address = Address;
        }

        public Design()
        {

        }

        public int ID { get; set; }

        [Required]
        [Display(Name = "Ingredient")]
        public eIngredient ingredient { get; set; }

        public string deliveryPersonnel { get; set; }

        [Required]
        [Display(Name = "Size")]
        public eSize size { get; set; }

        public ePayment payment { get; set; }

        public eArea area { get; set; }

        public decimal cost { get; set; }

        public bool complete { get; set; }

        public string Address { get; set; }

        public enum eIngredient
        {
            Cheese,
            Capers,
            Banana,
            Avocado,
            Chicken,
            Anchovies,
            Sausage,
            Mince
            
        }

       
        public enum ePayment
        {
            cash,
            EFT
        }

        public enum eSize
        {
            Small,
            Medium,
            Large
        }
        public enum eArea
        {
            Hatfield,
            Pretoria_North,
            Germiston,
            Athlone,
            Polokwane
        }
    }
}