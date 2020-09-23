Initializing the NDT localizer {#avp-demo-test-ndt}
==============================

# NDT initialization check

* [Start LGSVL](https://autowarefoundation.gitlab.io/autoware.auto/AutowareAuto/lgsvl.html)
* Start `ms3_sim.launch.py`
* In RViz, select the `map` fixed frame, make sure the map visualization is enabled and you have a good top-down view
* Start the simulation ("[ERROR] [localization.p2d_ndt_localizer_node]: Could not find a connection between 'map' and 'base_link' because they are not part of the same tree.Tf has two or more unconnected trees." messages are expected)
* In RViz, click on "2D pose estimation" and then click/drag on the position of the vehicle such that the arrow points in the same direction as the car
* You should now see a tf visualization (the red-blue-green axes) appearing at that location and the error messages stopping

![RViz before localization initialization](../images/avp_before_localization.png)
![RViz after localization initialization](../images/avp_after_localization.png)