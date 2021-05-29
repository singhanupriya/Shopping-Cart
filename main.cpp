#include<iostream>
#include<vector>

using namespace std;

class Person{
	
	protected:
		
		string m_name;
		int m_age;
		string m_gender;
		string m_mobileNumber;
	
	
		Person(string name, int age, string gender, string mobileNumber)
		{
			m_name=name;
			m_age=age;
			m_gender=gender;
			m_mobileNumber=mobileNumber;
		}
		
		void get_person_detail()
		{
			cout<<"Name: "<<m_name<<"\n"
			<<"Age: "<<m_age<<"\n"
			<<"Gender: "<<m_gender<<"\n"
			<<"Mobile Number: "<<m_mobileNumber<<"\n";
		}
	
};

class Employee:protected Person{
	
	int m_employeeID;
	string m_department;
	
	public:
		
		Employee(string name, int age, string gender, string mobileNumber, int employeeID, string department):Person(name, age, gender, mobileNumber)
		{
			m_employeeID=employeeID;
			m_department=department;
		}
		
		void get_employee_detail()
		{
			cout<<"Employee Details: \n";
			get_person_detail();
			
			cout<<"Employee ID: "<<m_employeeID<<"\n"
			<<"Employee Department: "<<m_department<<"\n\n";
		}
		
		
	
};

class Customer:protected Person{
	
	string m_subscription;
	string m_address;
	
	public:
		
		Customer(string name, int age, string gender, string mobileNumber, string subscription, string address):Person(name, age, gender, mobileNumber)
		{
			m_subscription=subscription;
			m_address=address;
		}
		
		void get_customer_detail()
		{
			cout<<"Customer Details: \n";
			get_person_detail();
			
			cout<<"Subscription: "<<m_subscription<<"\n"
			<<"Address: "<<m_address<<"\n\n";
		}
};

class Product{
	
	int m_productID;
	string m_productName;
	int m_productQuantity;
	float m_productDiscount;
	float m_productCostPerItem;
	float m_totalProductCost;
	
	public:
		
		Product()
		{
			m_productID=0;
			m_productName="";
			m_productQuantity=0;
			m_productDiscount=0.0;
			m_productCostPerItem=0.0;
		}
	
		Product(int productID, string productName, int productQuantity, float productDiscount, float productCostPerItem)
		{
			m_productID=productID;
			m_productName=productName;
			m_productQuantity=productQuantity;
			m_productDiscount=productDiscount;
			m_productCostPerItem=productCostPerItem;
			
		
		}
		
		
		
		void get_product_detail()
		{
			cout<<"Product Detail \n"
			<<"Product ID: "<<m_productID<<"\n"
			<<"Product Name: "<<m_productName<<"\n"
			<<"Product Quantity: "<<m_productQuantity<<"\n"
			<<"Product Discount(%): "<<m_productDiscount<<"\n"
			<<"Product Cost per Item: "<<m_productCostPerItem<<"\n\n";
		}
		
		int get_productID()
		{
			return m_productID;
		}
		
		float get_total_product_cost()
		{
			m_totalProductCost=m_productQuantity * (m_productCostPerItem - m_productDiscount);
		}
	
	
	
	
	
};


class Cart{
	
	
	vector<Product> basket;
	int itemsInCart=0;
	
	public:
		
		Cart()
		{
			cout<<basket.size()<<"\n";
			
		}
		
		
		void add_product(int productID, string productName, int productQuantity, float productDiscount, float productCostPerItem)
		
		{
			Product p(productID, productName, productQuantity, productDiscount, productCostPerItem);
			basket.push_back(p);
			itemsInCart++;
			
		}
		
		void remove_product(int productID)
		{
			int flag=0;
			for(int i=0;i<basket.size();i++)
			{
				if(basket[i].get_productID()==productID)
				{
					cout<<"Product removed successfully\n\n";
					//cout<<basket[i].size()<<"\n";
					//basket[i].~Product();
					flag=1;
					break;
				}
				
			}
			if(flag==0)
			{
				cout<<"Item not in the cart\n\n";
			}
			
		}
		
		
		void view_cart()
		{
			cout<<"Items in your Cart: \n";
			for(int i=0;i<basket.size();i++)
			{
				basket[i].get_product_detail();
			}
		}
		
		
		void get_items_in_cart()
		{
			cout<<"Items in the cart: "<<itemsInCart<<"\n";
		}
		
		float get_bill()
		{
			float sum=0;
			for(int i=0;i<basket.size();i++)
			{
				sum=sum+ basket[i].get_total_product_cost();
			}
			return sum;
		}
		
	
	
	
};




int main()
{
	
	Employee e("Anu",23,"F","1234567890",123,"Sales");
	e.get_employee_detail();
	
	Customer cus("Shaumya",34,"M","7654321987","Platinum","Dynasty, Wakad, Pune");
	cus.get_customer_detail();
	
	
	
	Cart c;
	c.add_product(123,"Curd",2,0.5,25.0);
	c.add_product(323,"Chips",5,0,15.0);
	c.add_product(1092,"Shoes",1,3.4,576);
	c.view_cart();
	c.remove_product(123);
	c.view_cart();
	c.get_items_in_cart();
	
	cout<<"Your total bill is "<<c.get_bill()<<"\n";
	
	
	
	
}
