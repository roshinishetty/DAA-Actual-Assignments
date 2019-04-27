#include<vector>

/*!
    Defines a point
*/    
class Point
{
    private:
        //! A private double x
        /*!
            X coordinate of point
        */
        double x;
        //! A private double y
        /*!
            Y coordinate of point
        */    
        double y;

    public:
        //! A public constructor of Point
        /*!
        */
        Point()
        {

        }
        //! A public constructor of Point
        /*!
            It takes 2 arguments x and y.
        */
        Point(double x, double y)
        {
            this->x=x;
            this->y=y;
        }
        //! A public constructor of Point
        /*!
        */
        double get_x()
        {
            return this->x;
        }
        double get_y()
        {
            return this->y;
        }
        void set_x(double temp)
        {
            this->x=temp;
        }
        void set_y(double temp)
        {
            this->y=temp;
        }

};
/*!
Defines a line
*/
class Line
{
    private:
        double slope,intercept;
        Point start, end;

    public:

        /*!
            Constructor using slope, intercept, start and end
        */    
         Line(double m,double c, Point&s, Point& e)
        {
            this->slope=m;
            this->intercept=c;    
            this->start=s;
            this->end=e;
        }

        /*!
            Constructor only start and end
        */    
        Line(Point& s, Point& e)
        {
            this->start=s;
            this->end=e;
            this->slope=(e.get_y()-s.get_y())/(e.get_x()-s.get_x());
            this->intercept=s.get_y()-(this->slope)*s.get_x();    
        }

        double getSlope()
        {
            return slope;
        }
        double getIntercept()
        {
            return intercept;
        }
        Point getStart()
        {
            return start;
        }
        Point getEnd()
        {
            return end;
        } 

};

