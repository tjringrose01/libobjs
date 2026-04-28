/**
 *  AssetManagement_gtest.cpp - Asset Management Model Tests
 */

#include <gtest/gtest.h>

#include <vector>

#include "Asset.hpp"
#include "AssetEvent.hpp"
#include "AssetModel.hpp"
#include "AssetType.hpp"
#include "Assignment.hpp"
#include "AuditResult.hpp"
#include "AuditSession.hpp"
#include "CustomFieldDefinition.hpp"
#include "CustomFieldValue.hpp"
#include "Department.hpp"
#include "DepreciationProfile.hpp"
#include "DisposalRecord.hpp"
#include "DocumentAttachment.hpp"
#include "Incident.hpp"
#include "InspectionRecord.hpp"
#include "Location.hpp"
#include "MaintenancePlan.hpp"
#include "Vendor.hpp"
#include "Warranty.hpp"
#include "WorkOrder.hpp"

TEST(AssetManagementTest, CoreAssetObjects) {
    const AssetType type("TYPE-1", "Laptop", "Portable computer", true);
    const AssetModel model("MODEL-1", "Lenovo", "T14", type, 36);
    const Location location("LOC-1", "HQ", "", "123 Main St");
    const Department department("DEP-1", "IT", "CC-10", "mgr-1");

    const Asset asset("ASSET-1",
                      "TAG-100",
                      "SN-123",
                      model,
                      AssetStatus::IN_STOCK,
                      location,
                      department,
                      "user-1");

    EXPECT_EQ("ASSET-1", asset.getAssetId());
    EXPECT_EQ("TAG-100", asset.getAssetTag());
    EXPECT_EQ("Laptop", asset.getModel().getAssetType().getName());
    EXPECT_EQ("HQ", asset.getLocation().getName());
    EXPECT_EQ("IT", asset.getOwningDepartment().getName());
}

TEST(AssetManagementTest, AssignmentAndEvents) {
    const Assignment assignment("A-1",
                                "ASSET-1",
                                "user-1",
                                Dt(2026, 4, 1),
                                Dt(2026, 4, 30),
                                "good",
                                "good",
                                true);

    const AssetEvent event("E-1",
                           "ASSET-1",
                           AssetEventType::ASSIGNED,
                           Dt(2026, 4, 1),
                           "admin-1",
                           "Assigned to user-1");

    EXPECT_TRUE(assignment.isActive());
    EXPECT_EQ("ASSET-1", assignment.getAssetId());
    EXPECT_EQ(AssetEventType::ASSIGNED, event.getEventType());
    EXPECT_NE(std::string::npos, event.to_string().find("ASSIGNED"));
}

TEST(AssetManagementTest, MaintenanceAndInspection) {
    const MaintenancePlan plan("MP-1", "ASSET-1", 90, Dt(2026, 7, 1), "V-1", "Quarterly check");
    const WorkOrder order("WO-1",
                          "ASSET-1",
                          Dt(2026, 6, 28),
                          Dt(2026, 6, 29),
                          WorkOrderStatus::COMPLETED,
                          "Fan replacement",
                          "V-1");
    const InspectionRecord inspection("INSP-1",
                                      "ASSET-1",
                                      Dt(2026, 7, 1),
                                      "aud-1",
                                      InspectionResult::PASSED,
                                      "All good");

    EXPECT_TRUE(plan.isDueOn(Dt(2026, 7, 1)));
    EXPECT_EQ(WorkOrderStatus::COMPLETED, order.getStatus());
    EXPECT_EQ(InspectionResult::PASSED, inspection.getResult());
}

TEST(AssetManagementTest, VendorWarrantyAndAttachments) {
    const Vendor vendor("V-1", "Acme Services", "Jane", "jane@example.com", "555-1212");
    const Warranty warranty("W-1",
                            "ASSET-1",
                            "V-1",
                            Dt(2026, 1, 1),
                            Dt(2028, 1, 1),
                            "Parts and labor");
    const DocumentAttachment attachment("ATT-1",
                                        "Asset",
                                        "ASSET-1",
                                        "/tmp/manual.pdf",
                                        "abc123",
                                        Dt(2026, 4, 28));

    EXPECT_EQ("Acme Services", vendor.getName());
    EXPECT_TRUE(warranty.isCoverageDate(Dt(2026, 1, 1)));
    EXPECT_EQ("Asset", attachment.getEntityType());
}

TEST(AssetManagementTest, IncidentDepreciationDisposal) {
    Incident incident("INC-1",
                      "ASSET-1",
                      Dt(2026, 4, 28),
                      IncidentSeverity::HIGH,
                      "Dropped device",
                      false);
    incident.setResolved(true);

    const DepreciationProfile profile("DP-1", DepreciationMethod::STRAIGHT_LINE, 60, 10.0);
    const DisposalRecord disposal("DISP-1",
                                  "ASSET-1",
                                  Dt(2030, 5, 1),
                                  "Recycle",
                                  "director-1",
                                  "End of life");

    EXPECT_TRUE(incident.isResolved());
    EXPECT_GT(profile.monthlyRate(), 0.0);
    EXPECT_EQ("Recycle", disposal.getMethod());
}

TEST(AssetManagementTest, AuditAndCustomFields) {
    AuditResult missing("AR-1", "ASSET-404", false, "Not found", "aud-1", Dt(2026, 4, 28));
    AuditResult found("AR-2", "ASSET-1", true, "Present", "aud-1", Dt(2026, 4, 28));

    AuditSession session("AS-1",
                         Dt(2026, 4, 28),
                         Dt(2026, 4, 29),
                         "LOC-1",
                         std::vector<AuditResult>{missing});
    session.addResult(found);

    const CustomFieldDefinition fieldDef("CFD-1",
                                         "Asset",
                                         "rack_position",
                                         CustomFieldType::TEXT,
                                         false);
    const CustomFieldValue fieldValue("CFD-1", "ASSET-1", "R1-U8", Dt(2026, 4, 28));

    EXPECT_EQ(static_cast<std::size_t>(1), session.missingCount());
    EXPECT_EQ(CustomFieldType::TEXT, fieldDef.getFieldType());
    EXPECT_EQ("R1-U8", fieldValue.getValue());
}
