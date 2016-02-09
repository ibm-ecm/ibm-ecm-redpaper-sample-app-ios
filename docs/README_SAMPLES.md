#Welcome

This document will provide you information about how to install and use the source code provided with the IBM Redpaper : "IBM Enterprise Content Management Mobile Application Implementation".

#Overview

The sample source code provided with this document is a collection of examples of what can be achieved with the adoption of the IBM ECM Mobile SDKs mentioned in the Redpaper.

The kit is composed by two sample apps for iOS : the IBM Case Manager Nearby Sample and the IBM Case Manager Capture Sample.

The IBM Case Manager Nearby Sample is intended to demonstrate the usage of the Case Manager SDK in the use case of an Inspector working remotely with his iPad. The app starts with a fullscreen map of the area around the user and shows a pin for each task located nearby.By tapping on the pin the user is able to lock or complete the task.
<br/>
More details on how to setup the location of a task can be found in chapter 3.3.2 of the Redpaper.

The IBM Case Manager Capture Sample combines the usage of the Case Manager and the Datacap Mobile SDK.<br/>
This app models the scenario where the user is required to provide information about a case (by completing some case properties) and submit some documents related to the case by uploading them to Datacap.

#Prerequisites

This document assumes the reader has a working knowledge of IBM Case Manager, Apple Xcode, and the Objective-C and Swift programming language.

#### SDK Prerequisites
Here are the prerequisites for using the SDK:

- An IBM Case Manager server that runs IBM Case Manager 5.2.1 or later
- An Apple Mac that runs OS X 10.10 or later with Xcode 7 or later installed
- The IBM Case Manager Mobile SDK 1.0.0.1 or later package
- The IBM Case Manager Mobile Configurator plugin 1.0.0.1 or later installed on the server

#Package
The package contains :
- ECM\_Redpaper\_SampleCode\_iOS: This sample code folder contains the following:
  - IBM-RedPaperSamples-iOS.xcworkspace :the workspace file that can be directly opened from Xcode
  - IBM-CaseManagerCaptureSample-iOS : a folder containing the source code for the Case Manager Capture Sample app
  - IBM-CaseManagerNearbySample-iOS : a folder containing the source code for the Case Manager Nearby Sample app


#Installation
Copy the archive on the Apple Mac where Xcode is installed.<br/>
Open the file IBM-RedPaperSamples-iOS.xcworkspace from Xcode.


