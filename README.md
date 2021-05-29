# Shopping-Cart


Person
string m_name
int m_age
string m_gender
string m_mobileNumber

protected:
void get_person_detail()

   

Employee
int m_employeeID
string m_department

public:
void get_employee_detail()
Customer
string m_subscription
string m_address

public:
void get_customer_detail()
	
      
Product
int m_productID
string m_productName
int m_productQuantity
float m_productDiscount
float m_productCostPerItem
float m_totalProductCost


public:
void get_product_detail()
int get_productID()
float get_total_product_cost()
Cart
vector<Product> basket
int itemsInCart=0

public:
void add_product()
void remove_product()
void view_cart()
void get_items_in_cart()
float get_bill()


  
 
