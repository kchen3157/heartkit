include make/helpers.mk
include make/neuralspot_config.mk
include make/neuralspot_toolchain.mk
include make/jlink.mk
include autogen.mk

# local_app_name := main <-- moved to autogen
TARGET = $(local_app_name)
sources := $(wildcard src/*.c)
sources += $(wildcard src/*.cc)
sources += $(wildcard src/*.cpp)
sources += $(wildcard src/*.s)
sources += $(wildcard src/ns-core/*.c)
sources += $(wildcard src/ns-core/*.cc)
sources += $(wildcard src/ns-core/*.cpp)
sources += $(wildcard src/ns-core/*.s)

# Cordio stack

INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/uecc
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/cfg
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/rscp
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/gatt
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/wsf/sources/util
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/hrps
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo4
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/wsf/include
INCLUDES+= extern/AmbiqSuite/R4.3.0/utils
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/services
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/sec/common
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/bas
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/wsf/sources/port/freertos
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/wsf/sources
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/hid
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/hci/ambiq
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/hci/ambiq/cooper
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/apps/app
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/hci
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/dm
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/l2c
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/apps/fit
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/uribeacon
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/include
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/apps
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/att
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/include
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/gap
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/FreeRTOSv10.1.1/Source/include
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/smp
INCLUDES+= extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/include/app

# Fit example INCLUDES
INCLUDES+= extern/AmbiqSuite/R4.3.0/boards/apollo4p_blue_kxr_evb/examples/ble/ble_freertos_fit/src

VPATH = ./includes/extern/AmbiqSuite/R4.3.0/third_party/uecc
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/cfg
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/rscp
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/sec/uecc
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/hid
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/hci/ambiq
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/hci/ambiq/cooper
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/gatt
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/apps/app
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/hci
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/dm
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/l2c
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/wsf/sources/util
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/FreeRTOSv10.1.1/Source/portable/MemMang
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/hrps
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/apps/fit
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/FreeRTOSv10.1.1/Source
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/att
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/FreeRTOSv10.1.1/Source/portable/GCC/AMapollo4
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/utils
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/services
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/gap
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/apps/hidapp
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/stack/smp
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-host/sources/sec/common
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/profiles/bas
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/devices
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/ble-profiles/sources/apps/app/common
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/third_party/cordio/wsf/sources/port/freertos

# Fit example sources
VPATH+=:./includes/extern/AmbiqSuite/R4.3.0/boards/apollo4p_blue_kxr_evb/examples/ble/ble_freertos_fit/src
# sources += ble_freertos_fit.c

sources += uECC.c
sources += uECC_ll.c
sources += cfg_stack.c
sources += rscps_main.c
sources += sec_ecc.c
sources += hid_main.c
sources += hci_evt.c
sources += hci_tr.c
sources += hci_cmd_past.c
sources += hci_vs_ae.c
sources += hci_core.c
sources += hci_cmd.c
sources += hci_cmd_ae.c
sources += hci_core_ps.c
sources += hci_cmd_phy.c
sources += hci_cmd_cte.c
sources += hci_drv_cooper.c
sources += hci_vs_cooper.c
sources += hci_dbg_trc.c
sources += gatt_main.c
sources += hci_main.c
sources += dm_priv.c
sources += dm_adv_ae.c
sources += dm_conn_sm.c
sources += dm_scan_leg.c
sources += dm_sync_ae.c
sources += dm_conn_slave.c
sources += dm_conn.c
sources += dm_sec_slave.c
sources += dm_dev_priv.c
sources += dm_conn_cte.c
sources += dm_conn_slave_leg.c
sources += dm_sec_lesc.c
sources += dm_scan.c
sources += dm_past.c
sources += dm_main.c
sources += dm_phy.c
sources += dm_sec.c
sources += dm_sec_master.c
sources += dm_scan_ae.c
sources += dm_conn_master_leg.c
sources += dm_adv_leg.c
sources += dm_conn_slave_ae.c
sources += dm_conn_master_ae.c
sources += dm_conn_master.c
sources += dm_dev.c
sources += dm_adv.c
sources += l2c_coc.c
sources += l2c_master.c
sources += l2c_slave.c
sources += l2c_main.c
sources += bda.c
sources += calc128.c
sources += print.c
sources += terminal.c
sources += bstream.c
sources += wstr.c
sources += crc32.c
sources += hrps_main.c
sources += fit_main.c
sources += atts_ccc.c
sources += attc_main.c
# sources += attc_eatt.c
sources += atts_ind.c
sources += attc_proc.c
sources += atts_write.c
sources += atts_csf.c
sources += att_uuid.c
sources += atts_proc.c
# sources += att_eatt.c
sources += att_main.c
# sources += atts_eatt.c
sources += atts_main.c
sources += atts_read.c
sources += atts_sign.c
sources += atts_dyn.c
sources += attc_write.c
sources += attc_disc.c
sources += attc_read.c
sources += attc_sign.c
sources += port.c
sources += gap_main.c
sources += hidapp_main.c
sources += smpr_sm.c
sources += smp_act.c
sources += smpr_sc_act.c
sources += smpi_sc_sm.c
sources += smpi_act.c
sources += smp_sc_main.c
sources += smpr_act.c
sources += smp_db.c
sources += smp_main.c
sources += smp_sc_act.c
sources += smpr_sc_sm.c
sources += smpi_sc_act.c
sources += smpi_sm.c
sources += smp_non.c
sources += sec_ecc_hci.c
sources += sec_aes.c
sources += sec_main.c
sources += sec_ecc_debug.c
sources += sec_aes_rev.c
sources += sec_ccm_hci.c
sources += sec_cmac_hci.c
sources += bas_main.c
sources += am_resources.c
sources += radio_task.c
sources += rtos.c
sources += app_db.c
sources += ui_lcd.c
sources += ui_main.c
sources += app_ui.c
sources += ui_console.c
sources += ui_timer.c
sources += ui_platform.c
sources += app_hw.c
sources += wsf_queue.c
sources += wsf_assert.c
sources += wsf_efs.c
sources += wsf_trace.c
sources += wsf_buf.c
sources += wsf_timer.c
sources += wsf_math.c
sources += wsf_os.c
sources += wsf_msg.c
sources += svc_px.c
sources += svc_rscs.c
sources += svc_gls.c
sources += svc_cte.c
sources += svc_hid.c
sources += svc_dis.c
sources += svc_temp.c
sources += svc_gyro.c
sources += svc_wdxs.c
sources += svc_cps.c
sources += svc_uricfg.c
sources += svc_wp.c
sources += svc_ipss.c
sources += svc_bps.c
sources += svc_hrs.c
sources += svc_wss.c
sources += svc_batt.c
sources += svc_alert.c
sources += svc_scpss.c
sources += svc_cscs.c
sources += svc_hts.c
sources += svc_plxs.c
sources += svc_time.c
sources += svc_core.c
sources += list.c
sources += queue.c
sources += timers.c
sources += tasks.c
sources += event_groups.c
sources += app_master.c
sources += app_master_ae.c
sources += app_disc.c
sources += app_terminal.c
sources += app_server.c
sources += app_main.c
sources += app_slave_ae.c
sources += app_slave_leg.c
sources += app_master_leg.c
sources += app_slave.c
sources += am_devices_cooper.c
sources += am_util_ble_cooper.c
# sources += heap_4.c


DEFINES+= SEC_ECC_CFG=SEC_ECC_CFG_HCI
DEFINES+= WSF_TRACE_ENABLED
DEFINES+= AM_DEBUG_PRINTF
DEFINES+= AM_BLE_USE_NVM
DEFINES+= AM_PART_APOLLO4P
DEFINES+= AM_FREERTOS


targets  := $(BINDIR)/$(local_app_name).axf
targets  += $(BINDIR)/$(local_app_name).bin

objects      = $(call source-to-object,$(sources))
dependencies = $(subst .o,.d,$(objects))

CFLAGS     += $(addprefix -D,$(DEFINES))
CFLAGS     += $(addprefix -I includes/,$(INCLUDES))
LINKER_FILE := libs/linker_script.ld

all: $(BINDIR) $(objects) $(targets)

.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	@echo "Windows_NT"
	@echo $(Q) $(RM) -rf $(BINDIR)/*
	$(Q) $(RM) -rf $(BINDIR)/*
else
	$(Q) $(RM) -rf $(BINDIR) $(JLINK_CF)
endif


$(BINDIR):
	$(Q) $(MKD) -p $@

$(BINDIR)/%.o: %.cc
	@echo " Compiling $(COMPILERNAME) $< to make $@"
	$(Q) $(MKD) -p $(@D)
	$(Q) $(CC) -c $(CFLAGS) $(CCFLAGS) $< -o $@

$(BINDIR)/%.o: %.cpp
	@echo " Compiling $(COMPILERNAME) $< to make $@"
	$(Q) $(MKD) -p $(@D)
	$(Q) $(CC) -c $(CFLAGS) $(CCFLAGS) $< -o $@

$(BINDIR)/%.o: %.c
	@echo " Compiling $(COMPILERNAME) $< to make $@"
	$(Q) $(MKD) -p $(@D)
	$(Q) $(CC) -c $(CFLAGS) $(CONLY_FLAGS) $< -o $@

$(BINDIR)/%.o: %.s
	@echo " Assembling $(COMPILERNAME) $<"
	$(Q) $(MKD) -p $(@D)
	$(Q) $(CC) -c $(CFLAGS) $< -o $@

$(BINDIR)/$(local_app_name).axf: $(objects)
	@echo " Linking $(COMPILERNAME) $@"
	$(Q) $(MKD) -p $(@D)
	$(Q) $(CC) -Wl,-T,$(LINKER_FILE) -o $@ $(objects) $(LFLAGS)

$(BINDIR)/$(local_app_name).bin: $(BINDIR)/$(local_app_name).axf
	@echo " Copying $(COMPILERNAME) $@..."
	$(Q) $(MKD) -p $(@D)
	$(Q) $(CP) $(CPFLAGS) $< $@
	$(Q) $(OD) $(ODFLAGS) $< > $(BINDIR)/$(local_app_name).lst
	$(Q) $(SIZE) $(objects) $(lib_prebuilt) $< > $(BINDIR)/$(local_app_name).size

$(JLINK_CF):
	@echo " Creating JLink command sequence input file..."
	$(Q) echo "ExitOnError 1" > $@
	$(Q) echo "Reset" >> $@
	$(Q) echo "LoadFile $(BINDIR)/$(TARGET).bin, $(JLINK_PF_ADDR)" >> $@
	$(Q) echo "Exit" >> $@

.PHONY: deploy
deploy: $(JLINK_CF)
	@echo " Deploying $< to device (ensure JLink USB connected and powered on)..."
	$(Q) $(JLINK) $(JLINK_CMD)
	$(Q) $(RM) $(JLINK_CF)

.PHONY: view
view:
	@echo " Printing SWO output (ensure JLink USB connected and powered on)..."
	$(Q) $(JLINK_SWO) $(JLINK_SWO_CMD)
	$(Q) $(RM) $(JLINK_CF)

%.d: ;
