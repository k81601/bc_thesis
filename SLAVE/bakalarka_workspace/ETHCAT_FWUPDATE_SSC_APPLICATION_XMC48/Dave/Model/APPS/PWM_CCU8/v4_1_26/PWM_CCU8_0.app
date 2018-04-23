<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="PWM_CCU8" URI="http://resources/4.1.26/app/PWM_CCU8/0" description="PWM APP using one timer slice of CCU8, with external events and dead time support, to generate up to 4 PWM outputs." mode="NOTSHARABLE" version="4.1.26" minDaveVersion="4.3.2" instanceLabel="PWM_CCU8_0" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="ccu8_global_signal" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_config_global" hwSignal="global_signal" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_period_match" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_period_match_interrupt" hwSignal="pmus_omds" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_ch1_cmp_match" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch1_compare_match_interrupt" hwSignal="cmd1s_cmu1s" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_ch2_cmp_match" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch2_compare_match_interrupt" hwSignal="cmd2s_cmu2s" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_0" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_event0_interrupt" hwSignal="e0as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_1" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_event1_interrupt" hwSignal="e1as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_2" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_event2_interrupt" hwSignal="e2as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="timer_st" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_st" hwSignal="st" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="timer_st1" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_sta" hwSignal="sta" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="timer_st2" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_stb" hwSignal="stb" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="pwm_ch1_direct" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch1_out_a" hwSignal="out0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="pwm_ch1_inverted" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch1_out_b" hwSignal="out1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="pwm_ch2_direct" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch2_out_a" hwSignal="out2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="pwm_ch2_inverted" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch2_out_b" hwSignal="out3" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ext_event0" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp0_unsync" hwSignal="gp0_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ext_event1" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp1_unsync" hwSignal="gp1_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ext_event2" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp2_unsync" hwSignal="gp2_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="gp0" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp0" hwSignal="gp0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="gp1" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp1" hwSignal="gp1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="gp2" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp2" hwSignal="gp2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ps" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ps" hwSignal="ps" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_0" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_mci0" hwSignal="mci0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_1" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_mci1" hwSignal="mci1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_2" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_mci2" hwSignal="mci2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_3" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_mci3" hwSignal="mci3" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcss_input" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_mcss" hwSignal="mcss" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="Out - CCU8 CH1 Direct PAD" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out0" hwSignal="pad" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="Out - CCU8 CH1 Invert PAD" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out1" hwSignal="pad" hwResource="//@hwResources.2"/>
  <virtualSignals name="Out - CCU8 CH2 Direct PAD" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out2" hwSignal="pad" hwResource="//@hwResources.3" required="false"/>
  <virtualSignals name="Out - CCU8 CH2 Invert PAD" URI="http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out3" hwSignal="pad" hwResource="//@hwResources.4" required="false"/>
  <virtualSignals name="PWM_CCU8 CH1 Direct Out_signal" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch1_out0" hwSignal="pin" hwResource="//@hwResources.5"/>
  <virtualSignals name="PWM_CCU8 CH1 Invert Out_signal" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch1_out1" hwSignal="pin" hwResource="//@hwResources.6"/>
  <virtualSignals name="PWM_CCU8 CH2 Direct Out_signal" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch2_out2" hwSignal="pin" hwResource="//@hwResources.7"/>
  <virtualSignals name="PWM_CCU8 CH2 Invert Out_signal" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch2_out3" hwSignal="pin" hwResource="//@hwResources.8"/>
  <requiredApps URI="http://resources/4.1.26/app/PWM_CCU8/0/pwm_ccu8_app_global_ccu8_cc8" requiredAppName="GLOBAL_CCU8" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#/"/>
  </requiredApps>
  <hwResources name="CC8 Config" URI="http://resources/4.1.26/app/PWM_CCU8/0/hwres_ccu8_cc8_slice" resourceGroupUri="peripheral/ccu8/*/cc8/*" mResGrpUri="peripheral/ccu8/*/cc8/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/ccu80/ccu80_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="PWM_CCU8 CH1 Direct Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/hwres_port_ch1_out0" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="PWM_CCU8 CH1 Invert Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/hwres_port_ch1_out1" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/port5/port5_5.dd#//@provided.23"/>
  </hwResources>
  <hwResources name="PWM_CCU8 CH2 Direct Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/hwres_port_ch2_out2" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="PWM_CCU8 CH2 Invert Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/hwres_port_ch2_out3" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="PWM_CCU8 CH1 Direct Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_hwres_port_ch1_out0" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="PWM_CCU8 CH1 Invert Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_hwres_port_ch1_out1" resourceGroupUri="devicepackage/0/58" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.14"/>
  </hwResources>
  <hwResources name="PWM_CCU8 CH2 Direct Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_hwres_port_ch2_out2" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="PWM_CCU8 CH2 Invert Out" URI="http://resources/4.1.26/app/PWM_CCU8/0/__pin_hwres_port_ch2_out3" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_global/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_config_global" systemDefined="true" sourceSignal="ccu8_global" targetSignal="ccu8_global_signal" targetVirtualSignal="//@virtualSignals.0" proxySrcVirtualSignalUri="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_global_sync_start/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp0_unsync" systemDefined="true" sourceSignal="ccu8_global_start" targetSignal="ext_event0" required="false" targetVirtualSignal="//@virtualSignals.14" proxySrcVirtualSignalUri="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_gsc_enable" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_global_sync_start/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp1_unsync" systemDefined="true" sourceSignal="ccu8_global_start" targetSignal="ext_event1" required="false" targetVirtualSignal="//@virtualSignals.15" proxySrcVirtualSignalUri="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_gsc_enable" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_global_sync_start/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_gp2_unsync" systemDefined="true" sourceSignal="ccu8_global_start" targetSignal="ext_event2" required="false" targetVirtualSignal="//@virtualSignals.16" proxySrcVirtualSignalUri="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_gsc_enable" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch1_out_a/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out0" systemDefined="true" sourceSignal="pwm_ch1_direct" targetSignal="Out - CCU8 CH1 Direct PAD" required="false" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.26"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch1_out_b/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out1" systemDefined="true" sourceSignal="pwm_ch1_inverted" targetSignal="Out - CCU8 CH1 Invert PAD" srcVirtualSignal="//@virtualSignals.11" targetVirtualSignal="//@virtualSignals.27"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch2_out_a/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out2" systemDefined="true" sourceSignal="pwm_ch2_direct" targetSignal="Out - CCU8 CH2 Direct PAD" required="false" srcVirtualSignal="//@virtualSignals.12" targetVirtualSignal="//@virtualSignals.28"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_ccu8_cc8_ch2_out_b/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out3" systemDefined="true" sourceSignal="pwm_ch2_inverted" targetSignal="Out - CCU8 CH2 Invert PAD" required="false" srcVirtualSignal="//@virtualSignals.13" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out0/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch1_out0" systemDefined="true" sourceSignal="Out - CCU8 CH1 Direct PAD" targetSignal="PWM_CCU8 CH1 Direct Out_signal" srcVirtualSignal="//@virtualSignals.26" targetVirtualSignal="//@virtualSignals.30"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch1_out0/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out0" systemDefined="true" sourceSignal="PWM_CCU8 CH1 Direct Out_signal" targetSignal="Out - CCU8 CH1 Direct PAD" srcVirtualSignal="//@virtualSignals.30" targetVirtualSignal="//@virtualSignals.26"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out1/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch1_out1" systemDefined="true" sourceSignal="Out - CCU8 CH1 Invert PAD" targetSignal="PWM_CCU8 CH1 Invert Out_signal" srcVirtualSignal="//@virtualSignals.27" targetVirtualSignal="//@virtualSignals.31"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch1_out1/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch1_out1" systemDefined="true" sourceSignal="PWM_CCU8 CH1 Invert Out_signal" targetSignal="Out - CCU8 CH1 Invert PAD" srcVirtualSignal="//@virtualSignals.31" targetVirtualSignal="//@virtualSignals.27"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out2/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch2_out2" systemDefined="true" sourceSignal="Out - CCU8 CH2 Direct PAD" targetSignal="PWM_CCU8 CH2 Direct Out_signal" srcVirtualSignal="//@virtualSignals.28" targetVirtualSignal="//@virtualSignals.32"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch2_out2/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out2" systemDefined="true" sourceSignal="PWM_CCU8 CH2 Direct Out_signal" targetSignal="Out - CCU8 CH2 Direct PAD" srcVirtualSignal="//@virtualSignals.32" targetVirtualSignal="//@virtualSignals.28"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out3/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch2_out3" systemDefined="true" sourceSignal="Out - CCU8 CH2 Invert PAD" targetSignal="PWM_CCU8 CH2 Invert Out_signal" srcVirtualSignal="//@virtualSignals.29" targetVirtualSignal="//@virtualSignals.33"/>
  <connections URI="http://resources/4.1.26/app/PWM_CCU8/0/http://resources/4.1.26/app/PWM_CCU8/0/__pin_vs_port_ch2_out3/http://resources/4.1.26/app/PWM_CCU8/0/vs_port_ch2_out3" systemDefined="true" sourceSignal="PWM_CCU8 CH2 Invert Out_signal" targetSignal="Out - CCU8 CH2 Invert PAD" srcVirtualSignal="//@virtualSignals.33" targetVirtualSignal="//@virtualSignals.29"/>
</ResourceModel:App>
