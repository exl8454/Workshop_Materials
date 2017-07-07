using UnityEngine;
using System.Collections;

[AddComponentMenu("CS/IMU Generic Controller")]
public class IMUGenericController : MonoBehaviour
{
    public enum Axis
    {
        ROLL,
        PITCH,
        YAW,
        DISABLE
    }

    public Axis xAxis, yAxis, zAxis;
    public bool invertX, invertY, invertZ;

    private IMUTracker tracker;
    private Vector3 newRot;

    void Awake()
    {
        tracker = FindObjectOfType<IMUTracker>().GetComponent<IMUTracker>();
    }

    void Update()
    {
        newRot = tracker.Rpya;
        switch (xAxis)
        {
            case Axis.ROLL: newRot.x = tracker.Rpya.x; break;
            case Axis.PITCH: newRot.x = tracker.Rpya.y; break;
            case Axis.YAW: newRot.x = tracker.Rpya.z; break;
            case Axis.DISABLE: newRot.x = 0; break;
        }
        switch (yAxis)
        {
            case Axis.ROLL: newRot.y = tracker.Rpya.x; break;
            case Axis.PITCH: newRot.y = tracker.Rpya.y; break;
            case Axis.YAW: newRot.y = tracker.Rpya.z; break;
            case Axis.DISABLE: newRot.y = 0; break;
        }
        switch (zAxis)
        {
            case Axis.ROLL: newRot.z = tracker.Rpya.x; break;
            case Axis.PITCH: newRot.z = tracker.Rpya.y; break;
            case Axis.YAW: newRot.z = tracker.Rpya.z; break;
            case Axis.DISABLE: newRot.z = 0; break;
        }
        if (invertX) newRot.x = -newRot.x;
        if (invertY) newRot.y = -newRot.y;
        if (invertZ) newRot.z = -newRot.z;
    }

    void LateUpdate()
    {
        this.transform.eulerAngles = newRot;
    }

    public Vector3 getRot()
    {
        return newRot;
    }
}
