using UnityEngine;
using System.Collections;

public class IMUGenericView : MonoBehaviour
{
    private LineRenderer line;
    private IMUGenericController controller;

    // Use this for initialization
    void Start()
    {
        controller = GetComponent<IMUGenericController>();
        line = GetComponent<LineRenderer>();
    }

    // Update is called once per frame
    void Update()
    {
        line.SetPosition(0, new Vector3(0, 0, 0));
        line.SetPosition(1, controller.getRot());
    }
}
