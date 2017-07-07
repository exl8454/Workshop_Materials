using UnityEngine;
using System.Collections;
using System;

[AddComponentMenu("CS/IMU Tracker")]
public class IMUTracker : MonoBehaviour
{
    [Range(0.0f, 1.0f)]
    public float smoothingFactor = 0.5f;

    public int portID = 2;

    public int baudrate = 9600;
    private Vector3 _rpya; // Current RPYA value
    private Vector3 _klmf; // Current KLMF value
    private Vector3 _gyro; // Current GYRO value
    private Vector3 _accl; // Current ACCL value
    private Vector3 _mgnt; // Current MGNT value

    private Vector3 rpya; // Filtered RPYA value
    private Vector3 klmf; // Filtered KLMF value
    private Vector3 gyro; // Filtered GYRO value
    private Vector3 accl; // Filtered ACCL value
    private Vector3 mgnt; // Filtered MGNT value

    private ComPort portListener;

    private string data;

    void Awake()
    {
        _rpya = new Vector3(0, 0, 0);
        _klmf = new Vector3(0, 0, 0);
        _gyro = new Vector3(0, 0, 0);
        _accl = new Vector3(0, 0, 0);
        _mgnt = new Vector3(0, 0, 0);

        rpya = new Vector3(0, 0, 0);
        klmf = new Vector3(0, 0, 0);
        gyro = new Vector3(0, 0, 0);
        accl = new Vector3(0, 0, 0);
        mgnt = new Vector3(0, 0, 0);

        portListener = new ComPort();
        portListener.PortID = "COM" + portID;
        if (portID > 10) portListener.PortID = "\\\\.\\COM" + portID;
        portListener.Baudrate = baudrate;

        portListener.Open();
    }

    void LateUpdate()
    {
        if (portListener.IsOpened)
        {
            if (Input.GetButtonUp("Jump"))
                Calibrate();
            else UpdateSensors();
        }
        else if (!portListener.IsOpened)
            portListener.Open();
    }

    void OnApplicationQuit()
    {
        portListener.Close();
    }

    private void UpdateSensors()
    {
        if (this.data != null)
        {
            // RPYA GYRO ACCL MGNT
            try
            {
                string[] data = this.data.Split(' ');
                string[] rpya = data[0].Split(':')[1].Split(',');
                //string[] klmf = data[1].Split(':')[1].Split(',');
                //string[] gyro = data[2].Split(':')[1].Split(',');
                //string[] accl = data[3].Split(':')[1].Split(',');
                //string[] mgnt = data[4].Split(':')[1].Split(',');

                _rpya.x = Single.Parse(rpya[0]);
                _rpya.y = Single.Parse(rpya[1]);
                _rpya.z = Single.Parse(rpya[2]);

                /*_klmf.x = Single.Parse(klmf[0]);
                _klmf.y = Single.Parse(klmf[1]);
                _klmf.z = Single.Parse(klmf[2]);*/

                /*_gyro.x = Single.Parse(gyro[0]);
                _gyro.y = Single.Parse(gyro[1]);
                _gyro.z = Single.Parse(gyro[2]);
 
                _accl.x = Single.Parse(accl[0]);
                _accl.y = Single.Parse(accl[1]);
                _accl.z = Single.Parse(accl[2]);
 
                _mgnt.x = Single.Parse(mgnt[0]);
                _mgnt.y = Single.Parse(mgnt[1]);
                _mgnt.z = Single.Parse(mgnt[2]);*/

                //this.rpya = _rpya;
                this.rpya = _rpya * smoothingFactor + (this.rpya * (1.0f - smoothingFactor));
                //this.klmf = _klmf * smoothingFactor + (this.klmf * (1.0f - smoothingFactor));
                //this.gyro = _gyro * smoothingFactor + (this.gyro * (1.0f - smoothingFactor));
                //this.accl = _accl * smoothingFactor + (this.accl * (1.0f - smoothingFactor));
                //this.mgnt = _mgnt * smoothingFactor + (this.mgnt * (1.0f - smoothingFactor));

                Debug.Log(this.rpya);
            }
            catch (NullReferenceException err) { Debug.Log("Data returned null"); }
            catch (IndexOutOfRangeException err) { Debug.Log("Insufficient data"); }

            portListener.Write("D");
            this.data = portListener.Read();
        }
        else
        {
            portListener.Write("D");
            this.data = portListener.Read();
        }
    }

    private void Calibrate()
    {
        portListener.Write("C");

        _rpya = new Vector3(0, 0, 0);
        _klmf = new Vector3(0, 0, 0);
        _gyro = new Vector3(0, 0, 0);
        _accl = new Vector3(0, 0, 0);
        _mgnt = new Vector3(0, 0, 0);

        rpya = new Vector3(0, 0, 0);
        klmf = new Vector3(0, 0, 0);
        gyro = new Vector3(0, 0, 0);
        accl = new Vector3(0, 0, 0);
        mgnt = new Vector3(0, 0, 0);
    }

    public Vector3 Rpya
    {
        get
        {
            return rpya;
        }
    }

    public Vector3 Klmf
    {
        get
        {
            return klmf;
        }
    }

    public Vector3 Gyro
    {
        get
        {
            return gyro;
        }
    }

    public Vector3 Accl
    {
        get
        {
            return accl;
        }
    }

    public Vector3 Mgnt
    {
        get
        {
            return mgnt;
        }
    }

    public Vector3 _Rpya
    {
        get
        {
            return _rpya;
        }
    }

    public Vector3 _Klmf
    {
        get
        {
            return _Klmf;
        }
    }

    public Vector3 _Gyro
    {
        get
        {
            return _gyro;
        }
    }

    public Vector3 _Accl
    {
        get
        {
            return _accl;
        }
    }

    public Vector3 _Mgnt
    {
        get
        {
            return _mgnt;
        }
    }
}
