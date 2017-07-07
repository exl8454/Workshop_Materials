using UnityEngine;
using System.Collections;
using System.IO.Ports;
using System;

// Allows communication between Arduino and Unity Engine
public class ComPort : MonoBehaviour
{
    private SerialPort port; // Serial port object
    private string portID; // Port ID to connect to
    private int baudrate; // Comm baudrate

    private bool isOpened; // Used to check port comm status

    public string PortID
    {
        get { return portID; }
        set { portID = value; }
    }
    public int Baudrate
    {
        get { return baudrate; }
        set { baudrate = value; }
    }
    public bool IsOpened
    {
        get { return isOpened; }
    }

    public ComPort() // Constructor
    {
        portID = "COM3";
        baudrate = 115200;
        isOpened = false;
    }

    public void Open()
    {
        if (port == null) // If port doesn't exist
            port = new SerialPort(portID, baudrate); // Create new port object
        else if (port.IsOpen) // If other port is already opened, close the port first
        {
            Close();
            Open();
        }

        try
        {
            port.Open(); // Open port
            port.ReadTimeout = 50; // Set timeout for reading from port

            if (port.IsOpen) // If port is opened, set status to opened
                isOpened = true;
            else isOpened = false;

            Debug.Log("Port Open Status : " + isOpened); // Just to let the dev knows
        }
        catch (Exception err) // Any error report to console
        {
            Debug.LogException(err);
        }
    }

    public void Close() // Closes communication, reset other variables
    {
        try
        {
            port.Close();
            isOpened = false;
            port = null;
        }
        catch (Exception err) // In case of any error, forse reset the port and report error
        {
            Debug.LogException(err);
            port = null;
            isOpened = false;
        }
    }

    public void Write(string line) // Write to arduino
    {
        try
        {
            port.Write(line);
        }
        catch (Exception err)
        {
            Debug.LogError(err);
        }
    }

    public string Read() // Read from arduino
    {
        string line = null;
        try
        {
            line = port.ReadLine();
        }
        catch (Exception err) // If no data is retrieved, return null
        {
            Debug.LogError(err);
            return null;
        }
        return line;
    }
}
