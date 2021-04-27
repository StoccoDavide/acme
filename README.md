# The ACME library

Given the amount of material out there one could certainly wonder why develop a new geometric library that will surely have fewer features than other libraries that represent the standard in the field. During my master thesis a large part of this code was developed [1]. The desire to extend the previous thesis work has made it necessary to better formalize and make more efficient the previously developed code.

ACME is small 3D computational geometry library which is currently still being developed. The library was build to be efficient, readable and easy-to-use. On the other hand users must remember the reference coordinate system of each geometrical object. The objects have not the possibility to store the coordinate system in which they are defined. For this reason, all transformations must be carried out by the user whenever necessary.

Since our design goals are the speed and robustness, we decided to embed the [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) template linear algebra library. In specific, dense matrix and array manipulation, space transformations are carried out by respecively using [Eigen Matrix](https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html) class and [Eigen Geometry](https://eigen.tuxfamily.org/dox/group__Geometry__chapter.html) module.

ACME is currently the foundation of a terrain server sofware running on a hard real-time DIL driving simulator. It resolves the geometrical intersection problems with a real-time factor (RTF) of 50.

### Online documentation
Available at: https://stoccodavide.github.io/acme/

### Maintenance
Library is being tested on Linux and MacOS, it will be soon tested also on Windows. If you have questions regarding the library or you want to report a bug, please open an [issue](https://github.com/StoccoDavide/acme/issues/new) at GitHub. If your request would contain confidential information, please [send me an email](davide.stocco@unitn.it).

### About the author

__Davide Stocco__<br/>
Department of Industrial Engineering<br/>
University of Trento<br/>
e-mail: <davide.stocco@unitn.it>

### References

1. *D. Stocco*, 
   **Real-Time Computation of Tire/Road Contact using Tailored Algorithms**,
   2020, Master Thesis (*in Italian*),
   [PDF](https://github.com/StoccoDavide/MasterThesis/blob/master/thesis.pdf).

